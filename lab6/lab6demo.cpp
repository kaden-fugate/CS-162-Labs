#include <iostream>

class Player{

    private:

        int n_books;
        int *books;

    public:

        Player(){

            std::cout << "C1 running \n";
            
            this->n_books = 0;

        }
        Player(int size){

            std::cout << "C2 running \n";

            this->n_books = size;
            this->books = new int[size];

        }
        Player(const Player &player){

            int temp_n_books;

            std::cout << "CC running \n";

            temp_n_books = player.n_books;

            this->n_books = temp_n_books;
            this->books = new int[player.n_books];

        }
        Player& operator=(const Player& player){

            int temp_n_books;

            std::cout << "AOO running \n";

            if(books == NULL){

                delete[] this->books;

            }

            temp_n_books = player.n_books;

            this->n_books = temp_n_books;
            this->books = new int[temp_n_books];

            return *this;
        }
        ~Player(){
            
            std::cout << "Destructor running" << "\n";
            delete[] books;
            books = NULL;

        }

};

int main(){

    Player p1(10);
    Player p2(5);

    p1 = p2;

    Player p3 = p2;

    return 0;

}