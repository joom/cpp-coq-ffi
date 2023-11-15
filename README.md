# cpp-coq-ffi

A primitive set data structure for Coq, using `std::set` from C++.

It currently has bugs, I'm working on it, this is only meant to be an experiment.

You can compile it by `make cpp`, and run `./prog`.

# Note

I'm committing the CertiCoq generated C files here, but I had to make a few changes in them:

- Added `GLUE_H` to the `glue.h` file
- Removed * from temp vars in `call` in `glue.c`
- Remove `printf` and `is_ptr` declarations from `glue.h`
- Remove `is_ptr` declaration from `prog.prog.c`
- Remove includes like `"home/coq/.opam/...."` from `prog.prog.c`
- Remove the definition of the `closure` struct from `glue.c`

So if you run `make coq`, you may have to do these.
