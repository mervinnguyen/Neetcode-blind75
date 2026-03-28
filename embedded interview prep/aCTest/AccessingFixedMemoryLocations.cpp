/**
 * @brief Access a fixed memory location and set its value.
 *
 * Demonstrates assigning a pointer to an absolute address (0x67a9) and setting the value at that address to 0xaa55.
 * Common in embedded systems for direct hardware or memory-mapped register access.
 */

#include <iostream>

using namespace std;

int main(){
    int *ptr;
    ptr = (int*)0x67a9;
    cout << "The current address of int is: " << ptr << endl;
    *ptr = 0xaa55;
    cout << "The current value at ptr is: " << *ptr << endl;
    return 0;
}   