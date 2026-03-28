/**
 * @file AccessingFixedMemoryLocations.cpp
 * @brief Demonstration of accessing fixed memory locations in embedded systems
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>

using namespace std;

/**
 * @brief Access a fixed memory location and set its value.
 *
 * Demonstrates assigning a pointer to an absolute address (0x67a9) and setting the value at that address to 0xaa55.
 * Common in embedded systems for direct hardware or memory-mapped register access.
 * 
 * @return Program exit status (0 for success)
 * 
 * @warning Writing to arbitrary memory addresses can cause system crashes or undefined behavior
 * @note Address 0x67a9 is used as an example and may not be valid on all systems
 */
int main(){
    int *ptr;
    ptr = (int*)0x67a9;
    cout << "The current address of int is: " << ptr << endl;
    *ptr = 0xaa55;
    cout << "The current value at ptr is: " << *ptr << endl;
    return 0;
}