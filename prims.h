#include "values.h"

value uint63_from_nat(value n);
value uint63_to_nat(struct thread_info *tinfo, value t);
value uint63_add(value x, value y);
value uint63_mul(value x, value y);

value set_runM(struct thread_info *tinfo, value a, value action);
