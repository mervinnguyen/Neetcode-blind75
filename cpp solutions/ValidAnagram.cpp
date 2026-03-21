//Valid anagram
//Given two string s and t, return true if the two strings are anagrams of each other, otherwise return false.
//An anagram is a string that contains the exact same characters as another string, but the order of the characters can be differnet.

//ex 1.
//input: s = "racecar", t = "carrace"
//output: false

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//1) Sort the string in alphabetical order 
class Solution{
    public:
        bool isAnagram(string s, string t){
            sort(s.begin(), s.end());    //sort string s in alphabetical order
            sort(t.begin(), t.end());    //sort string t in alphabetical order
            return (s == t);
        }
};

int main(){
    Solution sol;       //create object to class Solution
    string s = "EmbeddedSystems";
    string t = "SystemsEmbedded";
    bool result = sol.isAnagram(s, t);

    cout << (result ? "true" : "false") << endl;    //print out true or false depending on result 
}