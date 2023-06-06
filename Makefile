CC=g++
FLAG=-Wall -Werror
OBJ=main.o hotel.o tools.o
BIN=HMS

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN) && ./$(BIN) hms_info.txt

main.o:main.cpp hotel.h tools.h
	$(CC) -c $(FLAG) main.cpp 
hotel.o:hotel.cpp hotel.h room.h tools.h
	$(CC) -c $(FLAG) hotel.cpp 
tools.o:tools.cpp tools.h
	$(CC) -c $(FLAG) tools.cpp 

clean:
	rm -rf $(OBJ) $(BIN)
	rm -rf *.h.gch *~
