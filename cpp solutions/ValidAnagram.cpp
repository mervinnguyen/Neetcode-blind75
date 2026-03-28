/**
 * @file ValidAnagram.cpp
 * @brief Implementation of anagram validation using string sorting approach
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief Solution class for anagram validation problems
 * 
 * Provides methods to determine if two strings are anagrams of each other
 * by utilizing string sorting and comparison techniques.
 */
class Solution{
    public:
        /**
         * @brief Determines if two strings are anagrams by sorting and comparing
         * 
         * An anagram is formed by rearranging the letters of another word using
         * all original letters exactly once. This implementation sorts both strings
         * alphabetically and compares the results for equality.
         * 
         * @param[in] s First input string to compare
         * @param[in] t Second input string to compare
         * @return true if strings are anagrams, false otherwise
         * 
         * @note Time Complexity: O(n log n) due to sorting operations
         * @note Space Complexity: O(1) auxiliary space (strings are modified in-place)
         */
        bool isAnagram(string s, string t){
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return (s == t);
        }
};

/**
 * @brief Main function demonstrating anagram validation
 * 
 * Creates test strings and validates whether they form anagrams using the
 * Solution class implementation.
 * 
 * @return 0 on successful execution
 */
int main(){
    Solution sol;
    string s = "EmbeddedSystems";
    string t = "SystemsEmbedded";
    bool result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl;
    return 0;
}