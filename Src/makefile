CXXARGS  = -Wall -Werror -pedantic
CXXFLAGS = -I. $(CXXARGS)
CXX = g++

all: tp0

tp0: main.cpp vector.h TiposHash.h Transaction.h TransactionInput.h TransactionOutput.h Block.o Transaction.o TransactionInput.o TransactionOutput.o cmdline.o
	$(CXX) $(CXXFLAGS) -o tp0 main.cpp Block.o cmdline.o Transaction.o TransactionInput.o TransactionOutput.o

cmdline.o: cmdline.cc cmdline.h
	$(CXX) $(CXXFLAGS) -c cmdline.cc

Block.o: Block.cpp Block.h
	$(CXX) $(CXXFLAGS) -c Block.cpp

Transaction.o: Transaction.cpp Transaction.h
	$(CXX) $(CXXFLAGS) -c Transaction.cpp

TransactionInput.o: TransactionInput.cpp TransactionInput.h
	$(CXX) $(CXXFLAGS) -c TransactionInput.cpp

Transaction.o: TransactionOutput.cpp TransactionOutput.h
	$(CXX) $(CXXFLAGS) -c TransactionOutput.cpp

clean:
	rm -f *.o tp0
