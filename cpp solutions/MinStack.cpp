//Min Stack
//Desgin a stack class that supports the push, pop, top, and getMin operations.
//MinStack() initialized the stack object.
//void push(int val) pushes the element on top of the stack
//void pop() removes the element on top of the stack
//int top() gets the element of the stack.
//int getMin() retrieves the minimum element in the stack.

//Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

//Output: [null,null,null,null,0,null,2,1]

// Explanation:
// MinStack minStack = new MinStack();
// minStack.push(1);
// minStack.push(2);
// minStack.push(0);
// minStack.getMin(); // return 0
// minStack.pop();
// minStack.top();    // return 2
// minStack.getMin(); // return 1

#include <iostream>
#include <stack>
#include <algorithm>        //use math functions

using namespace std;

// 1) To push a value, append it to the stack
// 2) To pop, remove the top element of the stack.
// 3) To top, return the last element.
// 4) To getmin, return the top of the min_stack.
class MinStack {
public:
    stack<int> main_stack;  //stores all the values
    stack<int> min_stack;   //keeps track of minimum value at each level.

    MinStack() {
    }

    void push(int val){
        main_stack.push(val);
        if (min_stack.empty()){
            min_stack.push(val);        //handle the beginning case when min stack is empty
        }
        int minimum = min(val, min_stack.top());  //compute the new minimum between value pushed and current minimum on minStack.
        min_stack.push(minimum);        //push new minimum onto min_stack;
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
    MinStack stack;     //create object to class MinStack

    stack.push(1);
    stack.push(2);
    cout << "Current element top of the stack is: " << stack.top() << endl;
    cout << "Current min stack is: " << stack.getMin() << endl;
    stack.pop();
    cout << "Current element top of the stack is: " << stack.top() << endl;
    cout << "Current min element of stack is: " << stack.getMin() << endl;
    
    return 0;
}