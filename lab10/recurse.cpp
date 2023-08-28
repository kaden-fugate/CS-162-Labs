#include <iostream>

void pattern(int, int);

int main(){

    pattern(8, 0);

    return 0;

}

void pattern(int n, int col){

    if(n > 0){

        pattern((n / 2), col);

    }

    for(int i = 0; i < n + col; i++){

        if(i < col){

            std::cout << "  ";

        }
        else{

            std::cout << "* ";

        }

    }
    std::cout << "\n";

    if(n > 0){

        pattern((n / 2), (n / 2) + col);

    }

}