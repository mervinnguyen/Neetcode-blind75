//Contains Duplicate
//Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
//Ex. Input: nums = [1,2,3,3]
//Output: true

//Ex 2. Input: nums = [1,2,3,4]
//Output: false
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

//Brute force:
//1) Sort array in order
//2) Iterate using a ranged-based for loop 
//3) During each iteration compare the current index with last index, if they are equal, return true, else return false.
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;   //create object sol to Solution       
    vector<int>nums = {1, 4, 3, 2};
    bool result = sol.hasDuplicate(nums);
    cout << (result ? "true" : "false") << endl;        //print true if true, else print false
    return 0;
}