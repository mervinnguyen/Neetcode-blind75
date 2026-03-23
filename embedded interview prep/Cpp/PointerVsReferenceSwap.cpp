//Pointer vs Reference Swap
//Implement two functions that swap the values of two integers using different parameter-passing mechanisms in C++.

//void swap_ptr(int *a, int *b);
//swaps the valyes pointed to by a and b using pointers

//void swap_ref(int &a, int &b);
//swaps the values of a and b using references.

//the main() function will:
// 1) read two 32-bit signed integers from std input
// 2) Call swap_ptr using one copy of the input values
// 3) call swap_ref using a separate fresh copy of the same input values
// 4) print the results after each swap

//You only need to implement the two swap functions

#include <iostream>
using namespace std;

void swap_ptr(int *a, int *b){
    int i = 0;
    int *temp = &i;              //set a temp pointer to store temp for swapping
    *temp = *a;                  //store the value pointing at a into temp address
    *a = *b;                     //store value pointing at b into a
    *b = *temp;                  //store value that we previously stored into temp back into b
}

void swap_ref(int &c, int &d){
    int temp = c;
    c = d;
    d = temp;
}

int main(){
    int x, y;
    cout << "Please enter a value for x: ";
    cin >> x;
    cout << "Please enter a value for y: ";
    cin >> y;

    int a = x, b = y;
    swap_ptr(&a, &b);
    cout << "After swap_ptr: a = " << a << " and b = " << b << "\n";

    int c = x, d = y;
    swap_ref(c, d);
    cout << "After swap_ref: c = " << c << " and d =" << d << "\n";

    return 0;
}