#ifndef NODE_H
#define NODE_H

class Node{
public:

	int val; // the value that this node stores

	Node *next; // a pointer to the next node in the list

	Node(); // head with nothing following it

	Node(int); // end of list node

	Node(int, Node*); // middle node
	
	~Node();
	
};

#endif