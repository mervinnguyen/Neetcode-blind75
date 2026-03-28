/**
 * @class Solution
 * @brief Counts the number of 1 bits in a 32-bit unsigned integer.
 *
 * @details
 * Approach:
 * - Iterate through all 32 bits of the integer.
 * - For each bit, check if it is 1 using (n & 1).
 * - Increment count for each 1 bit found.
 * - Shift n right by 1 after each check.
 */

#include <iostream>
#include <cstdint>

using namespace std;
class Solution{
public:
    int hammingWeight(uint32_t n){
        int count = 0;
        for (int i = 0; i < 32; i++){
            count += (n & 1);    
            n >>= 1;   
        }
        return count;
    }
};

int main(){
    Solution sol;      
    uint32_t n = 0b00000000000001000001000000100100;
    cout << "The number of 1's is: " << sol.hammingWeight(n) << endl;
    return 0;
}