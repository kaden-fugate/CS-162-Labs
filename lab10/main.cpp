#include <iostream>
#include "linked_list.h"

void pause(){

    std::cout << "\n\nPress <enter> to continue...";
    std::cin.clear();
    std::cin.ignore(256, '\n');

}

void get_choice(Linked_List &link){ // get user choice for what to do with linked list

    int choice;
    int num;
    unsigned int index;

    while(true){

        std::cout << "Please enter desired choice: \n\n";

        std::cout << "Choice 1: add to front\n";
        std::cout << "Choice 2: add to back\n";
        std::cout << "Choice 3: insert at index\n";
        std::cout << "Choice 4: print list\n";
        std::cout << "Choice 5: quit\n";

        std::cout << ">";
        std::cin >> choice;
        std::cout << "\n";

        switch(choice){

            case 1: // add to front of list

                std::cout << "in 1\n";

                std::cout << "Please enter desired num: ";
                std::cin >> num;
                std::cout << "\n";

                link.push_front(num);

                continue;

            case 2: // add to back of list

                std::cout << "in 2\n";

                std::cout << "Please enter desired num: ";
                std::cin >> num;
                std::cout << "\n";

                link.push_back(num);

                continue;

            case 3: // insert in list

                std::cout << "in 3\n";

                std::cout << "Please enter desired num: ";
                std::cin >> num;
                std::cout << "\n";

                std::cout << "Please enter desired index: ";
                std::cin >> index;
                std::cout << "\n";

                link.insert(num, index);

                continue;

            case 4: // print

                std::cout << "in 4\n";

                link.print();
                
                continue;

            case 5: // quit

                std::cout << "in 5\n";

                link.clear();
                break;

            default:

                std::cout << "\nInvalid Input!\n";

        }

        std::cin.ignore();

    }

}


int main(){

    Linked_List list;

    get_choice(list);

}