From CertiCoq.Plugin Require Import CertiCoq.

Module Type UInt63.
  Axiom t : Type.
  Axiom from_nat : nat -> t.
  Axiom to_nat : t -> nat.
  Axiom add : t -> t -> t.
  Axiom mul : t -> t -> t.
End UInt63.

Module UInt63C : UInt63.
  Axiom t : Type.
  Axiom from_nat : nat -> t.
  Axiom to_nat : t -> nat.
  Axiom add : t -> t -> t.
  Axiom mul : t -> t -> t.
End UInt63C.

  CertiCoq Register [
    UInt63C.from_nat => "uint63_from_nat",
    UInt63C.to_nat => "uint63_to_nat" with tinfo,
    UInt63C.add => "uint63_add"
  ]
  Include [ "uint63_prims.h" ].

Class Hashable (A : Type) : Type :=
  { hash : A -> UInt63C.t }.

#[global] Instance Hashable_nat : Hashable nat :=
  {| hash := UInt63C.from_nat |}.

Module Type Sets.
  Axiom M      : Type -> Type -> Type.
  Axiom Sets   : Type -> Type -> Type.
  Axiom pure   : forall {S A}, A -> M S A.
  Axiom bind   : forall {S A B}, M S A -> (A -> M S B) -> M S B.
  Axiom new    : forall {S K} `{Hashable K}, M S (Sets S K).
  Axiom lookup : forall {S K} `{Hashable K}, Sets S K -> K -> M S bool.
  Axiom insert : forall {S K} `{Hashable K}, Sets S K -> K -> M S unit.
  Axiom delete : forall {S K} `{Hashable K}, Sets S K -> K -> M S unit.
  Axiom runM   : forall {A}, (forall S, M S A) -> A.
End Sets.

Module SetsC <: Sets.
  Axiom Sets : Type -> Type -> Type.
  Inductive MI (S : Type) : Type -> Type :=
  | pureI   : forall {A}, A -> MI S A
  | bindI   : forall {A B}, MI S A -> (A -> MI S B) -> MI S B
  | newI    : forall {K} `{Hashable K}, MI S (Sets S K)
  | lookupI : forall {K} `{Hashable K}, Sets S K -> K -> MI S bool
  | insertI : forall {K} `{Hashable K}, Sets S K -> K -> MI S unit
  | deleteI : forall {K} `{Hashable K}, Sets S K -> K -> MI S unit.

  Definition M : Type -> Type -> Type := MI.
  Definition pure   : forall {S A}, A -> M S A := @pureI.
  Definition bind   : forall {S A B}, M S A -> (A -> M S B) -> M S B := @bindI.
  Definition new    : forall {S K} `{Hashable K}, M S (Sets S K) := @newI.
  Definition lookup : forall {S K} `{Hashable K}, Sets S K -> K -> M S bool := @lookupI.
  Definition insert : forall {S K} `{Hashable K}, Sets S K -> K -> M S unit := @insertI.
  Definition delete : forall {S K} `{Hashable K}, Sets S K -> K -> M S unit := @deleteI.
  Axiom runM : forall {A}, (forall S, M S A) -> A.
End SetsC.

CertiCoq Register [ SetsC.runM => "set_runM" with tinfo ] Include [ "set_prims.h" ].

Notation "e1 ;; e2" :=
  (@SetsC.bind _ _ _ e1 (fun _ => e2)) (at level 61, right associativity).
Notation "x <- c1 ;; c2" :=
  (@SetsC.bind _ _ _ c1 (fun x => c2)) (at level 61, c1 at next level, right associativity).

Definition prog : bool :=
  SetsC.runM (fun s => 
    s <- SetsC.new ;;
    SetsC.insert s 1 ;;
    SetsC.insert s 2 ;;
    SetsC.insert s 3 ;;
    SetsC.lookup s 0).

CertiCoq Compile prog.
CertiCoq Generate Glue -file "glue" [ bool, nat, SetsC.MI, Hashable ].
