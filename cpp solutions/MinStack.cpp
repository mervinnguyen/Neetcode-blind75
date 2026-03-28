/**
 * @class MinStack
 * @brief Stack supporting push, pop, top, and retrieving the minimum element in O(1) time.
 *
 * @details
 * Approach:
 * - Use two stacks: one for all values (main_stack), one for the minimum at each level (min_stack).
 * - On push, add value to main_stack and the new minimum to min_stack.
 * - On pop, remove from both stacks.
 * - top() returns the top of main_stack.
 * - getMin() returns the top of min_stack.
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
class MinStack {
public:
    stack<int> main_stack;
    stack<int> min_stack;

    /*default constructor for MinStack class*/
    MinStack() {}
    
    void push(int val){
        main_stack.push(val);
        if (min_stack.empty()){
            min_stack.push(val);
        } else {
            int minimum = min(val, min_stack.top());  
            min_stack.push(minimum);   
        }   
    }

    void pop(){
        main_stack.pop();
        min_stack.pop();
    }

    int top(){
        return main_stack.top();
    }

    int getMin(){
        return min_stack.top();
    }
};

int main(){
    MinStack stack; 
    stack.push(1);
    stack.push(2);
    cout << "Current element top of the stack is: " << stack.top() << endl;     //2
    cout << "Current min stack is: " << stack.getMin() << endl;                 //1
    stack.pop();
    cout << "Current element top of the stack is: " << stack.top() << endl;     //1
    cout << "Current min element of stack is: " << stack.getMin() << endl;      //1
    return 0;
}