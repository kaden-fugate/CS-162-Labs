CC=g++
EXE_FILE=shape_run

all: $(EXE_FILE)

$(EXE_FILE): shape_class.o rectangle_class.o circle_class.o square_class.o main.cpp
	$(CC) shape_class.o rectangle_class.o circle_class.o square_class.o main.cpp -o $(EXE_FILE)
	clear

debug: shape_class.o rectangle_class.o circle_class.o square_class.o main.cpp
	$(CC) shape_class.o rectangle_class.o circle_class.o square_class.o main.cpp -g -o $(EXE_FILE)
	clear

shape_class.o: shape_class.cpp shapeheader.h
	$(CC) -c shape_class.cpp

rectangle_class.o: rectangle_class.cpp rectangleheader.h
	$(CC) -c rectangle_class.cpp

circle_class.o: circle_class.cpp circleheader.h
	$(CC) -c circle_class.cpp

square_class.o: square_class.cpp squareheader.h
	$(CC) -c square_class.cpp

clean:
	rm -f *.o $(EXE_FILE)
	clear
