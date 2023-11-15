extern "C" {
  #include "gc_stack.c"
  #include "glue.c"
  #include "prog.prog.c"
}

#include "prims.cpp"
#include <iostream>

int main() {
  struct thread_info* tinfo = make_tinfo();
  value tmp = body(tinfo);

  print_Coq_Init_Datatypes_bool(tmp);

  std::cout << "";
  return 0;
}
