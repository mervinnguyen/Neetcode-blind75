/**
 * @file 3Sum.cpp
 * @brief Finds all unique triplets in an array that sum to zero (brute-force approach).
 *
 * Uses a set to avoid duplicate triplets and triple-nested loops to check all combinations.
 */

/**
 * @class Solution
 * @brief Provides a brute-force method to find all unique triplets that sum to zero.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
class Solution {
public:
    /**
     * @brief Returns all unique triplets in the array that sum to zero.
     *
     * @param nums Reference to the input vector of integers.
     * @return Vector of unique triplets that sum to zero.
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        set<vector<int>> set;
        sort(nums.begin(), nums.end());
        if (nums.empty()) {
            return {};
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        set.insert(triplet);
                    }
                }
            }
        }
        return vector<vector<int>>(set.begin(), set.end());
    }
};

int main() {
    Solution sol;
    vector<int> input_num = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> new_vector = sol.threeSum(input_num);
    cout << "The triplets that sum to zero are:\n";
    for (const auto &triplet : new_vector) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}