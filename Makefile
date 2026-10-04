all: main

CXX = g++
override CXXFLAGS += -g -Wall

SRCS_WIN = src/main.cpp src/complex.cpp
SRCS_TEST_WIN = src/main_test.cpp src/complex.cpp tests/catch_amalgamated.o
HEADERS_WIN = src/complex.h
SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS_WIN) $(HEADERS_WIN)
	$(CXX) $(CXXFLAGS) $(SRCS_WIN) -o "$@"

main-debug: $(SRCS_TEST_WIN) $(HEADERS_WIN)
	$(CXX) $(CXXFLAGS) $(SRCS_TEST_WIN) -I tests -o "$@"

clean:
	del ./main.exe