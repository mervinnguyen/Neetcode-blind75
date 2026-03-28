/**
 * @class Solution
 * @brief Finds the single number in an array where every other number appears twice.
 *
 * Uses bitwise XOR to cancel out duplicate numbers, leaving only the unique number.
 * Time Complexity: O(n), Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    int singleNumber(vector<int> &nums){
        int result = 0;
        for (int num : nums){
            result ^= num; // XOR cancels out duplicates, leaves the unique number
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 3};
    cout << "Single number is: " << sol.singleNumber(nums) << endl;
    return 0;
}