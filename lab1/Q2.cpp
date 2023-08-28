/* CS 162- Lab 1 - Q.2
 * Solution description: call the function foo using "reference" to see the values before and after the function
 */
 
#include <iostream>

using namespace std;

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;
    /*Set b to half its original value*/
	*b = *b / 2;
    /*Assign a+b to c*/
	c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x = 7;
	int* px = &x;
	int y = 8;
	int* py = &y; 
	int z = 9;
	int* pz = &z;
    /*Print the values of x, y and z*/
	//cout << x << y << z << endl;
    /*Call foo() appropriately, passing x,y,z as parameters*/
	foo(px, py, z);
    /*Print the value returned by foo*/
	cout << foo(px, py, z);
    /*Print the values of x, y and z again*/
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
    /*Is the return value different than the value of z?  Why? */
    return 0;
}
    
    
