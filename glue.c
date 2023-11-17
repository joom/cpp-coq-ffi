#pragma once
#include "gc_stack.h"
#include "glue.h"
struct closure;
struct closure {
  value (*func)(struct thread_info, value, value);
  value env;
};

unsigned int get_unboxed_ordinal(value);
unsigned int get_boxed_ordinal(value);
value *get_args(value);
value make_Coq_Init_Datatypes_bool_true(void);
value make_Coq_Init_Datatypes_bool_false(void);
value make_Coq_Init_Datatypes_nat_O(void);
value make_Coq_Init_Datatypes_nat_S(value, value *);
value alloc_make_Coq_Init_Datatypes_nat_S(struct thread_info *, value);
value make_prog_Hashable_Build_Hashable(value, value *);
value alloc_make_prog_Hashable_Build_Hashable(struct thread_info *, value);
value make_Coq_Init_Datatypes_unit_tt(void);
value make_prog_SetsC_MI_pureI(value, value, value *);
value alloc_make_prog_SetsC_MI_pureI(struct thread_info *, value, value);
value make_prog_SetsC_MI_bindI(value, value, value, value, value *);
value alloc_make_prog_SetsC_MI_bindI(struct thread_info *, value, value, value, value);
value make_prog_SetsC_MI_newI(value, value, value *);
value alloc_make_prog_SetsC_MI_newI(struct thread_info *, value, value);
value make_prog_SetsC_MI_lookupI(value, value, value, value, value *);
value alloc_make_prog_SetsC_MI_lookupI(struct thread_info *, value, value, value, value);
value make_prog_SetsC_MI_insertI(value, value, value, value, value *);
value alloc_make_prog_SetsC_MI_insertI(struct thread_info *, value, value, value, value);
value make_prog_SetsC_MI_deleteI(value, value, value, value, value *);
value alloc_make_prog_SetsC_MI_deleteI(struct thread_info *, value, value, value, value);
unsigned int get_Coq_Init_Datatypes_bool_tag(value);
unsigned int get_Coq_Init_Datatypes_nat_tag(value);
unsigned int get_prog_Hashable_tag(value);
unsigned int get_Coq_Init_Datatypes_unit_tag(value);
unsigned int get_prog_SetsC_MI_tag(value);
void print_Coq_Init_Datatypes_bool(value);
void print_Coq_Init_Datatypes_nat(value);
void print_prog_Hashable(value, void (*)(value));
void print_Coq_Init_Datatypes_unit(value);
void print_prog_SetsC_MI(value, void (*)(value));
value call(struct thread_info *, value, value);
signed char const lparen_lit[2] = { 40, 0, };

signed char const rparen_lit[2] = { 41, 0, };

signed char const space_lit[2] = { 32, 0, };

signed char const fun_lit[6] = { 60, 102, 117, 110, 62, 0, };

signed char const type_lit[7] = { 60, 116, 121, 112, 101, 62, 0, };

signed char const unk_lit[6] = { 60, 117, 110, 107, 62, 0, };

signed char const prop_lit[7] = { 60, 112, 114, 111, 112, 62, 0, };

unsigned int get_unboxed_ordinal(value $v)
{
  return (unsigned long long) $v >> 1LL;
}

unsigned int get_boxed_ordinal(value $v)
{
  return (unsigned long long) *((unsigned long long *) $v + -1LL) & 255LL;
}

value *get_args(value $v)
{
  return (value *) $v;
}

signed char const names_of_Coq_Init_Datatypes_bool[2][6] = { 116, 114, 117,
  101, 0, 0, 102, 97, 108, 115, 101, 0, /* skip 0 */ };

signed char const names_of_Coq_Init_Datatypes_nat[2][2] = { 79, 0, 83, 0,
  /* skip 0 */ };

signed char const names_of_prog_Hashable[1][15] = { 66, 117, 105, 108, 100,
  95, 72, 97, 115, 104, 97, 98, 108, 101, 0, /* skip 0 */ };

signed char const names_of_Coq_Init_Datatypes_unit[1][3] = { 116, 116, 0,
  /* skip 0 */ };

signed char const names_of_prog_SetsC_MI[6][8] = { 112, 117, 114, 101, 73, 0,
  0, 0, 98, 105, 110, 100, 73, 0, 0, 0, 110, 101, 119, 73, 0, 0, 0, 0, 108,
  111, 111, 107, 117, 112, 73, 0, 105, 110, 115, 101, 114, 116, 73, 0, 100,
  101, 108, 101, 116, 101, 73, 0, /* skip 0 */ };

value make_Coq_Init_Datatypes_bool_true(void)
{
  return 1;
}

value make_Coq_Init_Datatypes_bool_false(void)
{
  return 3;
}

value make_Coq_Init_Datatypes_nat_O(void)
{
  return 1;
}

value make_Coq_Init_Datatypes_nat_S(value $arg0, value *$argv)
{
  *($argv + 0LL) = (value) 1024LL;
  *($argv + 1LL) = $arg0;
  return $argv + 1LL;
}

value alloc_make_Coq_Init_Datatypes_nat_S(struct thread_info *$tinfo, value $arg0)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 1024LL;
  *($argv + 1LL) = $arg0;
  (*$tinfo).alloc = (*$tinfo).alloc + 2LL;
  return $argv + 1LL;
}

value make_prog_Hashable_Build_Hashable(value $arg0, value *$argv)
{
  *($argv + 0LL) = (value) 1024LL;
  *($argv + 1LL) = $arg0;
  return $argv + 1LL;
}

value alloc_make_prog_Hashable_Build_Hashable(struct thread_info *$tinfo, value $arg0)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 1024LL;
  *($argv + 1LL) = $arg0;
  (*$tinfo).alloc = (*$tinfo).alloc + 2LL;
  return $argv + 1LL;
}

value make_Coq_Init_Datatypes_unit_tt(void)
{
  return 1;
}

value make_prog_SetsC_MI_pureI(value $arg0, value $arg1, value *$argv)
{
  *($argv + 0LL) = (value) 2048LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  return $argv + 1LL;
}

value alloc_make_prog_SetsC_MI_pureI(struct thread_info *$tinfo, value $arg0, value $arg1)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 2048LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  (*$tinfo).alloc = (*$tinfo).alloc + 3LL;
  return $argv + 1LL;
}

value make_prog_SetsC_MI_bindI(value $arg0, value $arg1, value $arg2, value $arg3, value *$argv)
{
  *($argv + 0LL) = (value) 4097LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  return $argv + 1LL;
}

value alloc_make_prog_SetsC_MI_bindI(struct thread_info *$tinfo, value $arg0, value $arg1, value $arg2, value $arg3)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 4097LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  (*$tinfo).alloc = (*$tinfo).alloc + 5LL;
  return $argv + 1LL;
}

value make_prog_SetsC_MI_newI(value $arg0, value $arg1, value *$argv)
{
  *($argv + 0LL) = (value) 2050LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  return $argv + 1LL;
}

value alloc_make_prog_SetsC_MI_newI(struct thread_info *$tinfo, value $arg0, value $arg1)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 2050LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  (*$tinfo).alloc = (*$tinfo).alloc + 3LL;
  return $argv + 1LL;
}

value make_prog_SetsC_MI_lookupI(value $arg0, value $arg1, value $arg2, value $arg3, value *$argv)
{
  *($argv + 0LL) = (value) 4099LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  return $argv + 1LL;
}

value alloc_make_prog_SetsC_MI_lookupI(struct thread_info *$tinfo, value $arg0, value $arg1, value $arg2, value $arg3)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 4099LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  (*$tinfo).alloc = (*$tinfo).alloc + 5LL;
  return $argv + 1LL;
}

value make_prog_SetsC_MI_insertI(value $arg0, value $arg1, value $arg2, value $arg3, value *$argv)
{
  *($argv + 0LL) = (value) 4100LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  return $argv + 1LL;
}

value alloc_make_prog_SetsC_MI_insertI(struct thread_info *$tinfo, value $arg0, value $arg1, value $arg2, value $arg3)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 4100LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  (*$tinfo).alloc = (*$tinfo).alloc + 5LL;
  return $argv + 1LL;
}

value make_prog_SetsC_MI_deleteI(value $arg0, value $arg1, value $arg2, value $arg3, value *$argv)
{
  *($argv + 0LL) = (value) 4101LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  return $argv + 1LL;
}

value alloc_make_prog_SetsC_MI_deleteI(struct thread_info *$tinfo, value $arg0, value $arg1, value $arg2, value $arg3)
{
  register value *$argv;
  $argv = (*$tinfo).alloc;
  *($argv + 0LL) = 4101LL;
  *($argv + 1LL) = $arg0;
  *($argv + 2LL) = $arg1;
  *($argv + 3LL) = $arg2;
  *($argv + 4LL) = $arg3;
  (*$tinfo).alloc = (*$tinfo).alloc + 5LL;
  return $argv + 1LL;
}

unsigned int get_Coq_Init_Datatypes_bool_tag(value $v)
{
  register unsigned int $t;
  $t = get_unboxed_ordinal($v);
  return $t;
}

unsigned int get_Coq_Init_Datatypes_nat_tag(value $v)
{
  register _Bool $b;
  register unsigned int $t;
  $b = is_ptr($v);
  if ($b) {
    $t = get_boxed_ordinal($v);
    switch ($t) {
      case 0:
        return 1U;
      
    }
  } else {
    $t = get_unboxed_ordinal($v);
    switch ($t) {
      case 0:
        return 0U;
      
    }
  }
}

unsigned int get_prog_Hashable_tag(value $v)
{
  register unsigned int $t;
  $t = get_boxed_ordinal($v);
  return $t;
}

unsigned int get_Coq_Init_Datatypes_unit_tag(value $v)
{
  register unsigned int $t;
  $t = get_unboxed_ordinal($v);
  return $t;
}

unsigned int get_prog_SetsC_MI_tag(value $v)
{
  register unsigned int $t;
  $t = get_boxed_ordinal($v);
  return $t;
}

void print_Coq_Init_Datatypes_bool(value $v)
{
  register unsigned int $tag;
  $tag = get_Coq_Init_Datatypes_bool_tag($v);
  printf(*(names_of_Coq_Init_Datatypes_bool + $tag));
}

void print_Coq_Init_Datatypes_nat(value $v)
{
  register unsigned int $tag;
  register void *$args;
  $tag = get_Coq_Init_Datatypes_nat_tag($v);
  switch ($tag) {
    case 0:
      printf(*(names_of_Coq_Init_Datatypes_nat + $tag));
      break;
    case 1:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_Coq_Init_Datatypes_nat + $tag));
      printf(space_lit);
      print_Coq_Init_Datatypes_nat(*((value *) $args + 0));
      printf(rparen_lit);
      break;
    
  }
}

void print_prog_Hashable(value $v, void $print_param_A(value))
{
  register unsigned int $tag;
  register void *$args;
  $tag = get_prog_Hashable_tag($v);
  switch ($tag) {
    case 0:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_prog_Hashable + $tag));
      printf(space_lit);
      printf(fun_lit);
      printf(rparen_lit);
      break;
    
  }
}

void print_Coq_Init_Datatypes_unit(value $v)
{
  register unsigned int $tag;
  $tag = get_Coq_Init_Datatypes_unit_tag($v);
  printf(*(names_of_Coq_Init_Datatypes_unit + $tag));
}

void print_prog_SetsC_MI(value $v, void $print_param_S(value))
{
  register unsigned int $tag;
  register void *$args;
  $tag = get_prog_SetsC_MI_tag($v);
  switch ($tag) {
    case 0:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_prog_SetsC_MI + $tag));
      printf(space_lit);
      printf(type_lit);
      printf(space_lit);
      printf(unk_lit);
      printf(rparen_lit);
      break;
    case 1:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_prog_SetsC_MI + $tag));
      printf(space_lit);
      printf(type_lit);
      printf(space_lit);
      printf(type_lit);
      printf(space_lit);
      printf(space_lit);
      printf(fun_lit);
      printf(rparen_lit);
      break;
    case 2:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_prog_SetsC_MI + $tag));
      printf(space_lit);
      printf(type_lit);
      printf(space_lit);
      printf(rparen_lit);
      break;
    case 3:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_prog_SetsC_MI + $tag));
      printf(space_lit);
      printf(type_lit);
      printf(space_lit);
      printf(space_lit);
      printf(unk_lit);
      printf(space_lit);
      printf(unk_lit);
      printf(rparen_lit);
      break;
    case 4:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_prog_SetsC_MI + $tag));
      printf(space_lit);
      printf(type_lit);
      printf(space_lit);
      printf(space_lit);
      printf(unk_lit);
      printf(space_lit);
      printf(unk_lit);
      printf(rparen_lit);
      break;
    case 5:
      $args = get_args($v);
      printf(lparen_lit);
      printf(*(names_of_prog_SetsC_MI + $tag));
      printf(space_lit);
      printf(type_lit);
      printf(space_lit);
      printf(space_lit);
      printf(unk_lit);
      printf(space_lit);
      printf(unk_lit);
      printf(rparen_lit);
      break;
    
  }
}

value call(struct thread_info *$tinfo, value $clo, value $arg)
{
  register value $f;
  register value $envi;
  register value $tmp;
  $f = (*((struct closure *) $clo)).func;
  $envi = (*((struct closure *) $clo)).env;
  $tmp =
    ((value (*)(struct thread_info *, value, value)) $f)
    ($tinfo, $envi, $arg);
  return $tmp;
}


