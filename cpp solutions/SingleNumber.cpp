//Single number 
//You are given a non-empty array of integers nums. Every integer appears twice except for one.
//Return the integer that appears only one.
//Return the integer that only appears once.
#include <iostream>
#include <vector>
using namespace std;

// 1) Use bit-wise "^" for O(n) complexity. Keep track using integer result
// 2) Iterate using range-based for loop over the vector. 
class Solution{
public:
    int singleNumber(vector<int> &nums){
        int result = 0;
        for (int num : nums){
            result ^= num;      //duplicates result to 0, single numbers result to num
        }
        return result;
    }
};

int main(){
    Solution sol;       //create object to class
    vector<int> nums = {1, 2, 2, 1, 3};
    cout << "Single number is: " << sol.singleNumber(nums) << endl;
    return 0;
}