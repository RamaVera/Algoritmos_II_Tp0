CXXARGS  = -Wall -Werror -pedantic
CXXFLAGS = -I. $(CXXARGS)
CXX = g++

all: tp0

tp0: main.cpp vector.h TiposHash.h Block.o cmdline.o
	$(CXX) $(CXXFLAGS) -o tp0 main.cpp Block.o cmdline.o

cmdline.o: cmdline.cc cmdline.h
	$(CXX) $(CXXFLAGS) -c cmdline.cc

Block.o: Block.cpp Block.h
	$(CXX) $(CXXFLAGS) -c Block.cpp

clean:
	rm -f *.o tp0
