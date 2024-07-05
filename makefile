

run : main.o board.o figure.o queen.o king.o bishop.o pawn.o rook.o knight.o 
	g++ main.o board.o figure.o queen.o king.o bishop.o pawn.o rook.o knight.o  -o run

main.o : main.cpp
	g++ -c main.cpp -o main.o

board.o : board.cpp
	g++ -c board.cpp -o board.o

figure.o : figure.cpp
	g++ -c figure.cpp -o figure.o

queen.o : queen.cpp 
	g++ -c queen.cpp -o queen.o

king.o : king.cpp
	g++ -c king.cpp -o king.o

bishop.o : bishop.cpp
	g++ -c bishop.cpp -o bishop.o

pawn.o : pawn.cpp
	g++ -c pawn.cpp -o pawn.o

rook.o : rook.cpp
	g++ -c rook.cpp -o rook.o

knight.o : knight.cpp
	g++ -c knight.cpp -o knight.o

