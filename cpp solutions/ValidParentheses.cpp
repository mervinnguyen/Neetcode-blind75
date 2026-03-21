//Valid parentheses
//You are given a string s consisting of the following
//characters: '(', ')', '{', '}','[', and ']'

//The input string s is valid if and only if:
//  1) Every open bracket is closed by the same type of closed bracket.
//  2) Open brackets are closed in the correct order.
//  3) Every close bracket has a corresponding open bracket of the same type

//Return true if s is a valid string, and false otherwise.

//ex 1)
//Input: s = "[]"
//Output: true

//ex 2)
//Input: s = "([{}])"
//Output: true

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Some possible questions to ask:
//1) Does input string s only contain brackets? Does it contain any characters?

// 1) Use a stack to store the characters.
// 2) Iterate through the string by index.
// 3) If its an opening bracket, push it onto the stack.
// 4) If its a closing bracket, check the top of the stack, and check if its corresponding to the closing bracke, if its not, return false.  
class Solution{
    public: 
        bool isValid(string s){
            stack<char> stack;      //declare a stack to store the characters
            for (int i = 0; i < s.size(); i++){     //iterate through the string
                if (s[i] == '{' || s[i] == '[' || s[i] == '('){
                    stack.push(s[i]);   //push index value into the stack
                }
                if (s[i] == '}' || s[i] == ']' || s[i] == ')'){
                    if (stack.empty()){       //check condition if stack is empty
                        return false;
                    }
                    char stack_top = stack.top();       //pop the top of the stack
                    if (s[i] == '}' && stack_top != '{' || s[i] == ']' && stack_top != '[' || s[i] == ')' && stack_top != '('){
                        return false;
                    } 
                    stack.pop();
                }

            }
            return stack.empty();    
        } 
};

int main(){
    Solution sol;       //create object to class
    string s = "{([])}";    //string input
    bool result = sol.isValid(s);
    cout << (result ? "true" : "false");
    return 0;
}