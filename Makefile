default: coq cpp

.PHONY: default clean coq cpp

clean:
	rm -f ./*.*.c
	rm -f ./*.*.h
	rm -f ./*.*.o
	rm -f ./glue.*.*.c
	rm -f ./glue.*.*.h
	rm -f ./glue.c
	rm -f ./glue.h
	rm -f ./*.vo
	rm -f ./*.vok
	rm -f ./*.vos
	rm -f ./*.glob

coq:
	coqc prog.v

cpp:
	g++ -std=c++20 -w -fpermissive -I ~/VeriFFI/certicoq/plugin/runtime -g -o prog main.cpp
