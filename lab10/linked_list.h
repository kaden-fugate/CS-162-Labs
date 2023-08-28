#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

class Linked_List {

private:

	unsigned int length; // the number of nodes contained in the list

	Node *head; // a pointer to the first node in the list

public:

	int get_length() const;

	Node* get_head() const;

	void print() const; // output a list of all integers contained within the list

	void clear(); // delete the entire list (remove all nodes and reset length to 0)

	void push_front(int); // insert a new value at the front of the list 

	void push_back(int); // insert a new value at the back of the list 

	void insert(int val, unsigned int index); // insert a new value in the list at the specified index

	void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm

	void sort_descending(); // sort the nodes in descending order
	
	// you can add extra member variables or functions as desired

	Linked_List();

	void split(Node*, Node**, Node**); // split linked list for merge sort

	void merge_sort(Node**); // merge sort func

	Node* sort(Node*, Node*); // merges two lists into one sorted list

	Node* recursive_selection(Node*); // selection sort func

	void swap(Node**, Node*, Node**, Node**); // function to swap nodes in selection sort function

};

unsigned int count_prime(Linked_List&); //count and return the number of prime numbers within the list

#endif