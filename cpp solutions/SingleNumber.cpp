/**
 * @file SingleNumber.cpp
 * @brief Implementation of single number finder using XOR operation
 * @author Author
 * @date 2024-12-19
 * @version 1.0.0
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Solution class for finding the single number in an array where every other number appears twice
 * 
 * Uses bitwise XOR property where A XOR A = 0 and A XOR 0 = A to cancel out duplicate numbers,
 * leaving only the unique number. Time Complexity: O(n), Space Complexity: O(1)
 */
class Solution{
public:
    /**
     * @brief Finds the single number that appears once while all others appear twice
     * @param[in] nums Vector of integers where all numbers appear twice except one
     * @return The single number that appears only once
     * @note Uses XOR operation which cancels out duplicates due to A XOR A = 0 property
     */
    int singleNumber(vector<int> &nums){
        int result = 0;
        for (int num : nums){
            result ^= num;
        }
        return result;
    }
};

/**
 * @brief Main function demonstrating the single number algorithm
 * @return Exit status code
 */
int main(){
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 3};
    cout << "Single number is: " << sol.singleNumber(nums) << endl;
    return 0;
}