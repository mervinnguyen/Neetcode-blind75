/**
 * @class Solution
 * @brief Checks for duplicates in an integer array.
 *
 * @details
 * Approach:
 * 1. Sort the array in order.
 * 2. Iterate through the array, comparing each element to the previous one.
 * 3. If any two consecutive elements are equal, return true (duplicate found).
 * 4. If no duplicates are found, return false.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
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
    Solution sol;
    vector<int> nums = {1, 4, 3, 2};
    bool result = sol.hasDuplicate(nums);
    cout << (result ? "true" : "false") << endl;
    return 0;
}