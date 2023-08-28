#include <iostream>
#include "node.h"

/*********************************************************************** 
** Function: Node()
** Description: this is the default constructor for the Node class.
** this constructor will not initialize a value and the next node will be set to NULL
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Node::Node() : next(NULL){}

/*********************************************************************** 
** Function: Node(int)
** Description: non default Node class constructor. constructs node with
** val and points to NULL
** Parameters: value of node
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Node::Node(int num) : val(num), next(NULL){}

/*********************************************************************** 
** Function: Node(int, Node*)
** Description: non default Node class constructor. constructs node with
** val and points to another Node
** Parameters: value of num, node being pointed to
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Node::Node(int num, Node *node) : val(num), next(node){}

/*********************************************************************** 
** Function: ~Node()
** Description: destructor for the Node class. This destructor works in a way
** that it calls itself over and over until its deleting the last one. after
** this all nodes including the one that was called to delete will be deleted.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Node::~Node(){

    if(this->next != NULL){

        delete this->next;
        this->next = NULL;

    }

}