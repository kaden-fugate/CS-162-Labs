#include <iostream>



struct multdiv_entry{

    int mult;
    float div;

};

int** create_table(int row, int col);

int main(){

    int row;
    int col;

    std::cout << "Please enter a number of rows greater than 0: ";
    std::cin >> row;
    std::cout << "\n\n";

    std::cout << "Please enter a number of columns greater than 0:";
    std::cin >> col;
    std::cout << "\n\n";

    struct multdiv_entry** create_table(row, col)

    return 0;

}

int** create_table(int row, int col){

    int mult** = new int*[row];
    float div** = new int*[row];

    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){

            mult[i][j] = i * j;
            div[i][j] = i / j;

        }
    }

    return mult, div;

}