extern "C" {
  #include "values.h"
  #include "gc_stack.h"
  #include "glue.h"
}
#include <cstddef>
#include <cstdint>
#include <set>
#include <iostream>

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

enum mi { PURE, BIND, NEW, LOOKUP, INSERT, DELETE };

value runM(struct thread_info *tinfo, value action) {
  BEGINFRAME(tinfo, 2)
  unsigned int tag = get_prog_SetsC_MI_tag(action);
  if (tag == PURE) {
    std::cout << "PURE\n";
    return get_args(action)[1];
  } else if (tag == BIND) {
    std::cout << "BIND\n";
    value arg0 = get_args(action)[2];
    value arg1 = get_args(action)[3];
    value temp = LIVEPOINTERS1(tinfo, runM(tinfo, arg0), arg0);
    temp = LIVEPOINTERS2(tinfo, call(tinfo, arg1, temp), arg1, temp);
    return runM(tinfo, temp);
  } else if (tag == NEW) {
    std::cout << "NEW\n";
    value hasher = get_args(get_args(action)[2])[0];
    auto cmp = [tinfo, hasher](value a, value b) { 
      return call(tinfo, hasher, a) < call(tinfo, hasher, b);
    };
    std::set<value, decltype(cmp)> s(cmp);
    std::cout << "The set has " << s.size() << " elements!\n";
    std::cout << "The set has " << ((std::set<value> *) ((void *) (&s)))->size() << " elements!\n";
    return (value) &s;
  } else if (tag == INSERT) {
    std::cout << "INSERT\n";
    value s = get_args(action)[2];
    value k = get_args(action)[3];
    std::set<value> *cast_set = (std::set<value> *) s;
    std::cout << "The set has " << cast_set->size() << " elements!\n";
    cast_set->insert(k);
    std::cout << "The set has " << cast_set->size() << " elements!\n";
    return make_Coq_Init_Datatypes_unit_tt();
  } else if (tag == DELETE) {
    std::cout << "DELETE\n";
    value s = get_args(action)[2];
    value k = get_args(action)[3];
    std::set<value> *cast_set = (std::set<value> *) s;
    cast_set->erase(k);
    return make_Coq_Init_Datatypes_unit_tt();
  } else if (tag == LOOKUP) {
    std::cout << "LOOKUP\n";
    value s = get_args(action)[2];
    value k = get_args(action)[3];
    std::set<value> *cast_set = (std::set<value> *) s;
    std::cout << "The set has " << cast_set->size() << " elements!\n";
    if (cast_set->count(k)) {
      return make_Coq_Init_Datatypes_bool_true();
    } else {
      return make_Coq_Init_Datatypes_bool_false();
    }
  } else {
    std::cout << "UNKNOWN CASE\n";
    exit(EXIT_FAILURE);
  }
  ENDFRAME
}

value set_runM(struct thread_info *tinfo, value a, value action) {
  return runM(tinfo, call(tinfo, action, 1));
}
