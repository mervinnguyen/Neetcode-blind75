//Reference Alias Update
//Given two signed 32-bit integers a and b, create a C++ reference taht aliases a.
//Update the value of a byt adding b only through this reference.

//Do not modify it directly after the reference is created.

//Print the updated value of a.

//Ex.
//Input: 5 3
//Output 8

#include <iostream>
#include <cstdint>
using namespace std;


int main(){
    int32_t a, b;
    cout << "Please enter a value for A: ";
    cin >> a;
    cout << "Please enter a value for B: ";
    cin >> b;

    //Write code here
    int &reference_a = a;        //set value to reference value a
    int &reference_b = b;        //set value to reference value b 

    //update reference value of a
    reference_a += b;

    cout << "The updated value of a is: " << a;
    return 0;
}