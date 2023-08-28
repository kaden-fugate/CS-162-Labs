/* CS162- Lab 1 - Q. 1*
 * Solution description: check the properties, like value and address, of pointer
 */
 
#include <iostream>

using namespace std;


void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     cout << "Value Pointed To:" << endl;
     cout << *iptr << endl;
     /*Print the address pointed to by iptr*/
     cout << "Address pointed to:" << endl;
     cout << &iptr << endl;
     /*Print the address of iptr itself*/
     cout << "Address of iptr:" << endl;
     cout << iptr << endl;
}

int main(){
    
    /*declare an integer x and initialize it with 0*/
    int x = 0;
    /*print the address of x*/
    int* px = &x;
    /*Call fooA() with the address of x*/
    fooA(px);
    /*print the value of x*/
    cout << "Value of x:" << endl;
    cout << x;

    return 0;
}
