/**
 * @file ValidParentheses.cpp
 * @brief Implementation of a bracket validation algorithm using stack data structure
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * @brief Solution class for bracket validation problems
 * 
 * @details
 * Approach:
 * - Use a stack to store opening brackets.
 * - Iterate through the string:
 * - If an opening bracket, push onto the stack.
 * - If a closing bracket, check if it matches the top of the stack.
 * - If not matching or stack is empty, return false.
 * - At the end, the stack should be empty for a valid string.
 */
class Solution{
public: 
    /**
     * @brief Validates if a string containing brackets is properly balanced
     * 
     * @param[in] s Input string containing brackets: '(', ')', '[', ']', '{', '}'
     * @return true if brackets are properly balanced and nested, false otherwise
     * 
     * @note Time complexity: O(n), Space complexity: O(n) where n is string length
     */
    bool isValid(string s){
        stack<char> stack;      
        for (int i = 0; i < s.size(); i++){    
            if (s[i] == '{' || s[i] == '[' || s[i] == '('){
                stack.push(s[i]);  
            }
            if (s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if (stack.empty()){  
                    return false;
                }
                char stack_top = stack.top();  
                if (s[i] == '}' && stack_top != '{' || s[i] == ']' && stack_top != '[' || s[i] == ')' && stack_top != '('){
                    return false;
                } 
                stack.pop();
            }
        }
        return stack.empty();    
    } 
};

/**
 * @brief Main function to demonstrate bracket validation
 * 
 * @return 0 on successful execution
 */
int main(){
    Solution sol;
    string s = "{([])}";
    bool result = sol.isValid(s);
    cout << (result ? "true" : "false");
    return 0;
}