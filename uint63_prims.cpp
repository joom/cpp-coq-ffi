extern "C" {
  #include <values.h>
  #include <gc_stack.h>
  #include "glue.h"
}
#include <any>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>

#define BEGINFRAME(tinfo,n) {{{{{ value __ROOT__[n];   \
   struct stack_frame __FRAME__ = { NULL/*bogus*/, __ROOT__, tinfo->fp }; \
   value __RTEMP__;

#define ENDFRAME }}}}}

#define LIVEPOINTERS1(tinfo, exp, a0) \
  (tinfo->fp= &__FRAME__, __FRAME__.next=__ROOT__+1, \
  __ROOT__[0]=(a0), __RTEMP__=(exp), (a0)=__ROOT__[0], \
  tinfo->fp=__FRAME__.prev, __RTEMP__)

#define LIVEPOINTERS2(tinfo, exp, a0, a1)	\
  (tinfo->fp= &__FRAME__, __FRAME__.next=__ROOT__+2, \
  __ROOT__[0]=(a0), __ROOT__[1]=(a1),		\
  __RTEMP__=(exp),                              \
  (a0)=__ROOT__[0], (a1)=__ROOT__[1],             \
  tinfo->fp=__FRAME__.prev, __RTEMP__)

enum nat { O, S };

value uint63_from_nat(value n) {
  value temp = n;
  uint64_t i = 0;

  while (get_Coq_Init_Datatypes_nat_tag(temp) == S) {
    i++;
    temp = get_args(temp)[0];
  }
  return (value) ((i << 1) + 1);
}

value uint63_to_nat(struct thread_info *tinfo, value t) {
  uint64_t i = (uint64_t) (((uint64_t) t) >> 1);
  value temp = make_Coq_Init_Datatypes_nat_O();
  BEGINFRAME(tinfo,1)
  while (i) {
   if (!(2 <= tinfo->limit - tinfo->alloc)) {
      tinfo->nalloc = 2;
      LIVEPOINTERS1(tinfo,(garbage_collect(tinfo),NULL),temp);
    } 
    temp = alloc_make_Coq_Init_Datatypes_nat_S(tinfo, temp);
    i--;
  }
  return temp;
  ENDFRAME
}

value uint63_add(value x, value y) {
  return (value) ((((((uint64_t) x) >> 1) + (((uint64_t) y) >> 1)) << 1) + 1);
}

value uint63_mul(value x, value y) {
  return (value) ((((((uint64_t) x) >> 1) * (((uint64_t) y) >> 1)) << 1) + 1);
}
