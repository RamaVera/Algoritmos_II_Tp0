
OBJECTS = main.o cmdline.o TransactionInput.o TransactionOutput.o Transaction.o Block.o BlockChainBuilder.o BlockChainFileManager.o BlockChainManager.o # Los archivos compilados individuales
PROGR = miner.exe # Nombre del archivo ejecutable
CPPFLAGS = -g -Wall -pedantic # -g opcion de g++ para debugear

# Compiladores #
CC = g++ -std=c++11 # Para linux
CCW = i686-w64-mingw32-g++ --static # Para windows (requiere mingw32)

$(PROGR) : $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(PROGR) $(OBJECTS)
main.o : main.cpp cmdline.h BlockChainManager.h
	$(CC) $(CPPFLAGS) -c main.cpp
cmdline.o : cmdline.cpp cmdline.h
	$(CC) $(CPPFLAGS) -c cmdline.cpp
BlockChainManager.o : BlockChainManager.cpp BlockChainManager.h BlockChainFileManager.h BlockChainBuilder.h
	$(CC) $(CPPFLAGS) -c BlockChainManager.cpp
BlockChainFileManager.o : BlockChainFileManager.cpp BlockChainFileManager.h BlockChainBuilder.h
	$(CC) $(CPPFLAGS) -c BlockChainFileManager.cpp
BlockChainBuilder.o : BlockChainBuilder.cpp BlockChainBuilder.h Block.h Transaction.h
	$(CC) $(CPPFLAGS) -c BlockChainBuilder.cpp
Block.o : Block.cpp Block.h Transaction.h Vector.h
	$(CC) $(CPPFLAGS) -c Block.cpp
Transaction.o : Transaction.cpp Transaction.h TransactionOutput.h TransactionInput.h 
	$(CC) $(CPPFLAGS) -c Transaction.cpp
TransactionOutput.o : TransactionOutput.cpp TransactionOutput.h
	$(CC) $(CPPFLAGS) -c TransactionOutput.cpp
TransactionInput.o : TransactionInput.cpp TransactionInput.h
	$(CC) $(CPPFLAGS) -c TransactionInput.cpp
	
	


clean:
	rm -f core $(PROGR) $(OBJECTS)
all: $(PROGR)
	$(CC) $(CPPFLAGS) -o $(PROGR) $(OBJECTS)
run : $(PROGR)
	valgrind --leak-check=yes ./$(PROGR)
