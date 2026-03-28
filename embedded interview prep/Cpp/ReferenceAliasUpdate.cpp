/**
 * @file ReferenceAliasUpdate.cpp
 * @brief Demonstrates C++ reference aliasing and indirect value modification
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>
#include <cstdint>
using namespace std;

/**
 * @brief Main function that demonstrates reference aliasing for indirect value modification
 * 
 * Creates a reference alias to variable 'a' and uses it to update the value
 * by adding variable 'b' without directly modifying 'a' after reference creation.
 * 
 * @return 0 on successful execution
 * 
 * @note Example: Input a=5, b=3 produces output 8
 */
int main(){
    int32_t a, b; /**< Input variables for the operation */
    cout << "Please enter a value for A: ";
    cin >> a;
    cout << "Please enter a value for B: ";
    cin >> b;

    int &reference_a = a; /**< Reference alias to variable a */
    int &reference_b = b; /**< Reference alias to variable b */

    reference_a += b; /**< Update a indirectly through its reference */

    cout << "The updated value of a is: " << a;
    return 0;
}