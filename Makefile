# enables c++11 on CAEN
PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

# designate which compiler to use
CXX			= g++
# list of test drivers (with main()) for development
TESTSOURCES = $(wildcard test*.cpp)
# list of objects used in tests
TESTOBJECTS = $(TESTSOURCES:%.cpp=%.o)
# names of test executables
TESTS       = $(TESTSOURCES:%.cpp=%)
# list of sources used in project
SOURCES 	= $(wildcard *.cpp)
#SOURCES     := $(filter-out $(TESTSOURCES), $(SOURCES))
# list of objects used in project
OBJECTS		= $(SOURCES:%.cpp=%.o)
# simplify testing if main() is in a file named projectX.cpp
PROJECTS    = $(wildcard project*.cpp) main.o
PROBJECTS   = $(PROJECTS:%.cpp=%.o)
# name of the executable produced by the top level
EXECUTABLE 	= tests

#Default Flags
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra -pedantic

# make release - will compile "all" with $(CXXFLAGS) and the -O3 flag
#				 also defines NDEBUG so that asserts will not check
release: CXXFLAGS += -O3 -DNDEBUG
release: all

# make debug - will compile "all" with $(CXXFLAGS) and the -g flag
#              also defines DEBUG so that "#ifdef DEBUG /*...*/ #endif" works
debug: CXXFLAGS += -g3 -DDEBUG
debug: clean all

# make profile - will compile "all" with $(CXXFLAGS) and the -pg flag
profile: CXXFLAGS += -pg
profile: clean all

# highest target; sews together all objects into executable
all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Automatically generate any build rules for test*.cpp files
define make_tests
OBJS = $$(filter-out $$(PROBJECTS), $$(OBJECTS))
$(1): $$(OBJS) $(1).o
	$$(CXX) $$(CXXFLAGS) $$(OBJS) $(1).o -o $(1)
endef
$(foreach test, $(TESTS), $(eval $(call make_tests, $(test))))


tests: CXXFLAGS += -pg -DDEBUG
tests: clean $(TESTS)

# individual dependencies for objects
# YOU NEED TO ADD YOUR OWN DEPENDENCIES HERE!!!

#test_linked_list_basic_functions.o: catch_source.o


# rule for creating objects
%.o:
	$(CXX) $(CXXFLAGS) -c $*.cpp

# make clean - remove .o files, executable, tarball
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TESTS)

rebuild: clean all

# these targets do not create any files
.PHONY: all release debug profile clean submit
# disable built-in rules
.SUFFIXES: