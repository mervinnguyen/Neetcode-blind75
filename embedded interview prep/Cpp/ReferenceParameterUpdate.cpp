/**
 * @file ReferenceParameterUpdate.cpp
 * @brief Program demonstrating reference parameter passing to update integer values
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>
#include <cstdint>
using namespace std;

/**
 * @brief Updates an integer value by adding a delta value
 * @param[in,out] x The integer to be updated (passed by reference)
 * @param[in] delta The value to add to x
 * @note Function modifies the original variable through reference parameter
 */
void update(int32_t &x, int32_t delta){
    x += delta;
}

/**
 * @brief Main function that reads input values, calls update function, and prints result
 * @return 0 on successful execution
 * @note Example: Input "10 4" produces Output "14"
 */
int main(){
    int32_t x = 0, delta = 0;
    cin >> x >> delta;

    update(x, delta);

    cout << x;
    return 0;
}