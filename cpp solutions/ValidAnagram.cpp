/**
 * @class Solution
 * @brief Checks if two strings are anagrams by sorting and comparing.
 *
 * Sorts both strings alphabetically and compares them for equality.
 * Time Complexity: O(n log n), Space Complexity: O(1) (ignoring sort implementation details)
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
        bool isAnagram(string s, string t){
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return (s == t);
        }
};

int main(){
    Solution sol;
    string s = "EmbeddedSystems";
    string t = "SystemsEmbedded";
    bool result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl;
    return 0;
}