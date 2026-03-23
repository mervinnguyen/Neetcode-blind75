//Refernce Parameter Update
//Write a function named update that takes an integer x by reference and integer delta by value.
//The function must update x by adding delta to it.
//In main(), read the input values, call the function, and print the updated value x.

//ex
//Input: 10 4
//Output: 14
#include <iostream>
#include <cstdint>  //allows for integer types (uint32_t, uint64_t, uint8_t, etc. )
using namespace std;

void update(int32_t &x, int32_t delta){
    //implement logic here
    x += delta;
}

int main(){
    int32_t x = 0, delta = 0;   //mental note: cannot bind reference values with a literal integer, can only bind with variables
    cin >> x >> delta;

    update(x, delta);

    cout << x;      //Print updated value
    return 0;
}