CC=g++
EXE_FILE=link

all: $(EXE_FILE)

$(EXE_FILE): node_class.o linked_class.o main.cpp
	$(CC) node_class.o linked_class.o main.cpp -o $(EXE_FILE);

linked_class.o: linked_list.h linked_class.cpp 
	$(CC) -c linked_class.cpp 

node_class.o: node.h node_class.cpp 
	$(CC) -c node_class.cpp

clean:
	rm -f *.o $(EXE_FILE)
	clear
