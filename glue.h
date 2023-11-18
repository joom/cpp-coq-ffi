#ifndef GLUE_H
#define GLUE_H
#include "gc_stack.h"
extern unsigned int get_unboxed_ordinal(value);
extern unsigned int get_boxed_ordinal(value);
extern value *get_args(value);
extern value make_Coq_Init_Datatypes_bool_true(void);
extern value make_Coq_Init_Datatypes_bool_false(void);
extern value make_Coq_Init_Datatypes_nat_O(void);
extern value make_Coq_Init_Datatypes_nat_S(value, value *);
extern value alloc_make_Coq_Init_Datatypes_nat_S(struct thread_info *, value);
extern value make_prog_Hashable_Build_Hashable(value, value *);
extern value alloc_make_prog_Hashable_Build_Hashable(struct thread_info *, value);
extern value make_Coq_Init_Datatypes_unit_tt(void);
extern value make_prog_SetsC_MI_pureI(value, value, value *);
extern value alloc_make_prog_SetsC_MI_pureI(struct thread_info *, value, value);
extern value make_prog_SetsC_MI_bindI(value, value, value, value, value *);
extern value alloc_make_prog_SetsC_MI_bindI(struct thread_info *, value, value, value, value);
extern value make_prog_SetsC_MI_newI(value, value, value *);
extern value alloc_make_prog_SetsC_MI_newI(struct thread_info *, value, value);
extern value make_prog_SetsC_MI_lookupI(value, value, value, value, value *);
extern value alloc_make_prog_SetsC_MI_lookupI(struct thread_info *, value, value, value, value);
extern value make_prog_SetsC_MI_insertI(value, value, value, value, value *);
extern value alloc_make_prog_SetsC_MI_insertI(struct thread_info *, value, value, value, value);
extern value make_prog_SetsC_MI_deleteI(value, value, value, value, value *);
extern value alloc_make_prog_SetsC_MI_deleteI(struct thread_info *, value, value, value, value);
extern unsigned int get_Coq_Init_Datatypes_bool_tag(value);
extern unsigned int get_Coq_Init_Datatypes_nat_tag(value);
extern unsigned int get_prog_Hashable_tag(value);
extern unsigned int get_Coq_Init_Datatypes_unit_tag(value);
extern unsigned int get_prog_SetsC_MI_tag(value);
extern void print_Coq_Init_Datatypes_bool(value);
extern void print_Coq_Init_Datatypes_nat(value);
extern void print_prog_Hashable(value, void (*)(value));
extern void print_Coq_Init_Datatypes_unit(value);
extern void print_prog_SetsC_MI(value, void (*)(value));
extern value call(struct thread_info *, value, value);
extern signed char const lparen_lit[2];

extern signed char const rparen_lit[2];

extern signed char const space_lit[2];

extern signed char const fun_lit[6];

extern signed char const type_lit[7];

extern signed char const unk_lit[6];

extern signed char const prop_lit[7];

extern signed char const names_of_Coq_Init_Datatypes_bool[2][6];

extern signed char const names_of_Coq_Init_Datatypes_nat[2][2];

extern signed char const names_of_prog_Hashable[1][15];

extern signed char const names_of_Coq_Init_Datatypes_unit[1][3];

extern signed char const names_of_prog_SetsC_MI[6][8];


#endif /* GLUE_H */
