CC  = g++
CXX = g++

INCLUDES =


CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)


LDFLAGS = -g


LDLIBS =


solverTest: solverTest.o solver.o

solverTest.o: solverTest.cpp solver.h

solver.o: solver.cpp solver.h


.PHONY: clean
clean:
	rm -f *.o solver solverTest

.PHONY: all
all: clean solverTest