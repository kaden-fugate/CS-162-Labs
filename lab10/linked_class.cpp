#include <iostream>
#include "linked_list.h"

/*********************************************************************** 
** Function: Linked_List()
** Description: this is the default contrustor for the Linked_List class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Linked_List::Linked_List() : length(0), head(new Node()){}

/*********************************************************************** 
** Function: get_length()
** Description: this function returns the length of the linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

int Linked_List::get_length() const { 

    return this->length;

}

/*********************************************************************** 
** Function: get_head
** Description: this function returns the head of the linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Node* Linked_List::get_head() const {

    return this->head;

}

/*********************************************************************** 
** Function: print()
** Description: this function prints every value in the linked list.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::print() const {

    if(this->head->next != NULL){ // doesnt print anything when list empty

        Node *temp = this->head->next; // prints next node because head has no value

        while(temp != NULL){

            std::cout << temp->val << " "; // print val
            temp = temp->next; // go to next val

        }
        std::cout << "\n";

    }

}


/*********************************************************************** 
** Function: clear()
** Description: this function deletes the head of the linked list.
** Node destructor works in a way that it recursively calls itself for the
** next node in the linked list until it reaches the end.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::clear(){

    delete this->head;
    this->head = NULL;

    this->length = 0;

}

/*********************************************************************** 
** Function: push_front(int)
** Description: this function adds a value at the first position in
** the linked list
** Parameters: value being added to the list
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::push_front(int val){

    Node *temp_node = NULL;
    Node *new_node = new Node(val); // Node with val pointing to nothing

    if(this->head->next != NULL){

        temp_node = this->head->next; // node to save vals in list

    }
    
    new_node->next = temp_node; 
    this->head->next = new_node; // swap nodes

    this->length++;
    
}

/*********************************************************************** 
** Function: push_back(int)
** Description: this function adds a new value to the end of the linked list.
** Parameters: value being added
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::push_back(int val){

    Node *cur_node = head;

    while(cur_node->next != NULL){

        cur_node = cur_node->next;

    }
    // cur_node is now at the end of the linked list

    cur_node->next = new Node(val); // end of the list now holds node with new val pointing to NULL

    this->length++;

}

/*********************************************************************** 
** Function: insert(int, unsigned int)
** Description: this function adds a new value at any position in the
** linked list.
** Parameters: value being added, position in the list
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::insert(int val, unsigned int index){

    if(index <= this->length || index < 0){ // check to make sure index is valid

        Node *cur_node = head;
        Node *temp_node;

        for(int i = 0; i < index; i++){ // cycle until we are pointing at the spot that we want to add node to

            cur_node = cur_node->next;

        }
        // set cur_node to point at index to insert
        
        temp_node = cur_node->next; // temp_node holds vals after inset index
        cur_node->next = new Node(val, temp_node); /* insert index is now node with new val pointing to
        next vals in list */
        
        this->length++;

    }

}

/*********************************************************************** 
** Function: sort_ascending()
** Description: this function calls a recursive merge sort function.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::sort_ascending(){

    merge_sort(&(this->head)->next); // & of head so it is modified

}

/*********************************************************************** 
** Function: sort_descending()
** Description: this function calls a recursive selection sort function.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::sort_descending(){

    this->head->next = recursive_selection((this->head)->next); // sets first val in list to sorted list

}

/*********************************************************************** 
** Function: merge_sort(Node**)
** Description: this function splits the list and merges itself back together
** in the correct order to be sorted. this function calls itself recursively until
** the list is empty or it only holds one value.
** Parameters: pointer to the head of the list that needs to be split.
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::merge_sort(Node **head){

    Node *temp_node = *head;
    Node *left, *right;

    if(temp_node == NULL || temp_node->next == NULL){ return; } // base case

    split(temp_node, &left, &right); // split the linked list

    merge_sort(&left); // call again with left to split that side
    merge_sort(&right); // call again with right to split that side

    *head = sort(left, right); // sort the two sides that we have

}

/*********************************************************************** 
** Function: split(Node*, Node**, Node**)
** Description: this function splits a single linked list into two linked lists.
** to do this, one node increases at a rate of 2 and another increases at a rate 
** of one. when the fast node reaches NULL, the lists will be split.
** Parameters: head of the given list, a pointer to the node of the left list,
** a pointer to the node of the right list.
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::split(Node *head, Node **left, Node **right){

    Node *left_list = head, *right_list = head->next;
        
    while(right_list->next != NULL){ // moves right side counter by two for everytime it moves left once

        right_list = right_list->next;

        if(right_list->next != NULL){

            right_list = right_list->next;
            left_list = left_list->next;

        }

    }
    
    *left = head; // left is now the head
    *right = left_list->next; // right is equal to everything not in left list
    left_list->next = NULL; // cut off right list vals from left list

}

/*********************************************************************** 
** Function: sort(Node*, Node*)
** Description: this function recursively calls itself to sort the list.
** the function will sort the left side and right side of the list
** all together into one new list. if either side of the list is empty,
** the recursion will end and return the new sorted list.
** Parameters: left list head node, right list head node
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Node* Linked_List::sort(Node *left, Node *right){

    Node* temp_node = left;

    Node *new_head = NULL;

    if(left == NULL){return right;} // if the left list is empty, sorted list will be right list
    if(right == NULL){return left;} // vice versa

    if(left->val < right->val){ // case for if left list val less than right list val

        new_head = left; // new_head is the linked list
        new_head->next = sort(left->next, right); // next val of left is replaced with next in sort order

    }
    else{ // vice versa with left >= right

        new_head = right;
        new_head->next = sort(left, right->next);

    }

    return new_head;

}

/*********************************************************************** 
** Function: recursive_selection(Node*)
** Description: this function sorts the list using a recursive selection
** sort algorithm. the function will iterate through the list and replace the first
** node in the head with the greatest value then call itself again to do that
** for the next values of the list after the newly sorted one.
** Parameters: the first node that contains a val in the linked list
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Node* Linked_List::recursive_selection(Node *head){

    if(head == NULL || head->next == NULL){ return head; } // if head is empty or has 1 val, return the head

    Node *temp_node = head;
    Node *max_node = head, *max_ptr = NULL; // max_ptr will be set to the node before max_node

    while(temp_node->next != NULL){ 

        if(temp_node->next->val > max_node->val){ // if new max found, update max_node and max_ptr

            max_node = temp_node->next;
            max_ptr = temp_node;

        }
        temp_node = temp_node->next;

    }

    if(max_node != head){
        swap(&head, head, &max_node, &max_ptr);
    }

    head->next = recursive_selection(head->next); // do this again for list of length n - 1

    return head; // all heads will return at end of recursion to make sorted list

}

/*********************************************************************** 
** Function: swap(Node**, Node*, Node**, Node**)
** Description: this function swaps the nodes for the selection sort algorithm.
** this function and the entire selection sort probably never wouldve been possible if
** TA Zach Coalson didn't give me super helpful advice on how i should make the function
** Parameters: pointer to the head of list being sorted, the next value in the list
** pointer to the max value in list, pointer to node before max value
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Linked_List::swap(Node **head, Node *head_next, Node **max, Node **max_ptr){

    (*head) = (*max); // head is max val
    (*max_ptr)->next = head_next; // max val is replaced with next val in head

    Node *temp_node = (*max)->next; // temp node to hold vals after max
    (*max)->next = head_next->next; // vals after max are now vals after head_next
    head_next->next = temp_node; // vals after head_next are replaced with vals after max val

} // shout out to TA Zach Coalson who gave me a hint on how to make this function work properly

/*********************************************************************** 
** Function: count_print(Linked_List&)
** Description: this function counts the number of primes contained within
** the linked list. vals 0 and 1 are not considered prime.
** Parameters: address of linked list being counted
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

unsigned int count_prime(Linked_List &list){

    int count = 0;
    Node *temp_node = list.get_head();
    temp_node = temp_node->next;

    while(temp_node != NULL){

        for(int j = 2; j < temp_node->val/2 + 1; j++){

            if(temp_node->val % j == 0){ break; }
            else if(temp_node->val % j != 0 && j == temp_node->val/2){ count++; }

        }
        
        if(temp_node->val == 2){count++;}
        temp_node = temp_node->next;

    }

    return count;

}