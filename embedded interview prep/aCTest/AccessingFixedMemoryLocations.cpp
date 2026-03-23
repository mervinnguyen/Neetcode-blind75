//Accessing Fixed memory locations
//Embedded Systems are often characterized by requiring the programmer to access a specific memory location. On a certain project, it is required to set an integer variable at the absolute address 0x67a9 to the value 0xaa55.
//The compiler is a pure ANSI compiler. Write code to accomplish this task.

#include <iostream>

using namespace std;        //export standard library for I/O
int main(){
    int *ptr;       //declare a pointer to integer in memory
    ptr = (int *) 0x67a9;       //assign address of integer to 0x67a9
    cout << "The current address of int is: " << ptr << endl;   //print current adress
    *ptr = 0xaa55;              //set value of the the integer to 0xaa55
    cout << "The current value at ptr is: " << *ptr << endl;
    return 0;
}   