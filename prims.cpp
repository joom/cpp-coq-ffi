extern "C" {
  #include "values.h"
  #include "gc_stack.h"
  #include "glue.h"
}
#include <any>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>
#include <set>
#include <vector>
 

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

/* #define DEBUG */
value runM(struct thread_info *tinfo, std::vector<std::any>& all_sets, value action) {
  BEGINFRAME(tinfo, 2)
  unsigned int tag = get_prog_SetsC_MI_tag(action);
  if (tag == PURE) {
    #ifdef DEBUG
      std::cout << "PURE\n";
    #endif
    return get_args(action)[1];
  } else if (tag == BIND) {
    #ifdef DEBUG
      std::cout << "BIND\n";
    #endif
    value arg0 = get_args(action)[2];
    value arg1 = get_args(action)[3];
    value temp = LIVEPOINTERS1(tinfo, runM(tinfo, all_sets, arg0), arg0);
    temp = LIVEPOINTERS2(tinfo, call(tinfo, arg1, temp), arg1, temp);
    return runM(tinfo, all_sets, temp);

  } else if (tag == NEW) {
    #ifdef DEBUG
      std::cout << "NEW\n";
    #endif
    value hasher = get_args(get_args(action)[1])[0];
    auto cmp = [tinfo, hasher](value a, value b) { 
      return call(tinfo, hasher, a) < call(tinfo, hasher, b);
    };
    std::set<value, decltype(cmp)> s(cmp);
    all_sets.push_back(std::make_any<std::set<value, decltype(cmp)>>(s));
    #ifdef DEBUG
      std::cout << "The set has " << s.size() << " elements!\n";
    #endif
    return (value) &s;

  } else if (tag == INSERT) {
    #ifdef DEBUG
      std::cout << "INSERT\n";
    #endif
    value hasher = get_args(get_args(action)[1])[0];
    auto cmp = [tinfo, hasher](value a, value b) { 
      return call(tinfo, hasher, a) < call(tinfo, hasher, b);
    };
    value s = get_args(action)[2];
    value key = get_args(action)[3];
    std::set<value, decltype(cmp)> *cast_set = (std::set<value, decltype(cmp)> *) s;
    #ifdef DEBUG
      std::cout << "The set has " << cast_set->size() << " elements!\n";
    #endif
    cast_set->insert(key);
    #ifdef DEBUG
      std::cout << "The set has " << cast_set->size() << " elements!\n";
    #endif
    return make_Coq_Init_Datatypes_unit_tt();

  } else if (tag == DELETE) {
    #ifdef DEBUG
    std::cout << "DELETE\n";
    #endif
    value hasher = get_args(get_args(action)[1])[0];
    auto cmp = [tinfo, hasher](value a, value b) { 
      return call(tinfo, hasher, a) < call(tinfo, hasher, b);
    };
    value s = get_args(action)[2];
    value key = get_args(action)[3];
    std::set<value, decltype(cmp)> *cast_set = (std::set<value, decltype(cmp)> *) s;
    cast_set->erase(key);
    return make_Coq_Init_Datatypes_unit_tt();

  } else if (tag == LOOKUP) {
    #ifdef DEBUG
      std::cout << "LOOKUP\n";
    #endif
    value hasher = get_args(get_args(action)[1])[0];
    auto cmp = [tinfo, hasher](value a, value b) { 
      return call(tinfo, hasher, a) < call(tinfo, hasher, b);
    };
    value s = get_args(action)[2];
    value key = get_args(action)[3];
    std::set<value, decltype(cmp)> *cast_set = (std::set<value, decltype(cmp)> *) s;
    #ifdef DEBUG
      std::cout << "The set has " << cast_set->size() << " elements!\n";
    #endif
    if (cast_set->count(key)) {
      return make_Coq_Init_Datatypes_bool_true();
    } else {
      return make_Coq_Init_Datatypes_bool_false();
    }

  } else {
    #ifdef DEBUG
      std::cout << "UNKNOWN CASE\n";
    #endif
    exit(EXIT_FAILURE);
  }
  ENDFRAME
}

value set_runM(struct thread_info *tinfo, value a, value action) {
  std::vector<std::any> all_sets = {};
  value temp = runM(tinfo, all_sets, call(tinfo, action, 1));
  // Empty all the sets
  for (int i = 0; i < all_sets.size(); i++){
    // FIXME this is causing a bad any cast error. 
    // Not sure how to fix it because all the sets have different types based on the cmp function.
    /* std::any_cast<std::set<value>>(all_sets[i].second).clear(); */
	}
  return temp;
}
