# cpp-coq-ffi

A primitive set data structure for Coq, using `std::set` from C++.

The example returns the right result but it may have other bugs. This is only meant to be an experiment.

You can compile it by `make cpp`, and run `./prog`.

# Note

I'm committing the CertiCoq generated C files here, but I had to make a few changes in them:

- Added `#ifndef GLUE_H` ... to the `glue.h` file.
- Removed * from temp vars in `call` in `glue.c`.
- Removed `printf` and `is_ptr` declarations from `glue.c`.
- Removed `is_ptr` declaration from `prog.prog.c`.
- Removed includes like `"home/coq/.opam/...."` from `prog.prog.c`.
- Removed the definition of the `closure` struct from `glue.c`.
- Added `#include "glue.h"` to `glue.c`.

So if you run `make coq`, you may have to do these.
