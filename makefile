STATIC_EXE = bin/staticTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(STATIC_EXE)
.PHONY: all run test_static test_dynamic memcheck_static memcheck_dynamic directories clean

run:$(STATIC_EXE)
	@echo "Press enter to run staticTest"
	@read DUMMY
	$(STATIC_EXE)
	@echo "Press enter to memcheck staticTest"
	@read DUMMY
	$(MEMCHECK) $(STATIC_EXE)

test_static: $(STATIC_EXE)
	$(STATIC_EXE)

memcheck_static: $(STATIC_EXE)
	$(MEMCHECK) $(STATIC_EXE)

directories:
	mkdir -p obj
	mkdir -p bin

clean: directories
	rm bin/*
	rm obj/*

$(STATIC_EXE):directories obj/StaticStringTest.o obj/StaticString.o
	$(CC) $(OPTIONS) $(DEBUG) -o $(STATIC_EXE) obj/StaticStringTest.o obj/StaticString.o

obj/StaticStringTest.o:directories src/StaticStringTest.cpp
	$(CC) $(OPTIONS) $(DEBUG) -o obj/StaticStringTest.o -c  -I inc/ src/StaticStringTest.cpp

obj/StaticString.o:directories src/StaticString.cpp inc/StaticString.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/StaticString.o -c  -I inc/ src/StaticString.cpp
