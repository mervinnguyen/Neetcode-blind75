//3 Sum
//Given an integer array, find all unique triplets that sum to zero.
//Input: nums = [-1, 0, 1, 2, -1, -4]
//Output: [[-1, -1, 2], [-1, 0, 1]]

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

//Brute force: 
// 1) Sort vector in increasing order
// 2) Use a triple-nested index for loop and append vector to 2D vector if the sum == 0
// 3) Return output of new generated vector

class Solution{
public: 
    vector<vector<int>> threeSum(vector<int> &nums){
        set<vector<int>> set;       //create set to keep track of duplicates
        sort(nums.begin(), nums.end());     //sort vector first
        if (nums.empty()){
            return {};      //note: pay attention to return type.
        }
        sort(nums.begin(), nums.end());     //sort vector in increasing order
        for (int i = 0; i < nums.size() - 2; i++){
            for (int j = i + 1; j < nums.size() - 1; j++){
                for (int k = j + 1; k < nums.size(); k++){
                    if (nums[i] + nums[j] + nums[k] == 0){
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        set.insert(triplet);
                    }
                }
            }
        }
        return vector<vector<int>>(set.begin(), set.end());
    }
};

int main(){
    Solution sol;

    vector<int> input_num = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> new_vector = sol.threeSum(input_num);

    cout << "The triplets that sum to zero are:\n";

    for (const auto &triplet : new_vector){
        cout << "[ ";
        for (int num : triplet){
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}