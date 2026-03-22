//Number of 1 Bits
//You are given an unsigned integer n. Return the number of 1 bits in binary representation
//You may assum n is a non-negative integer which fits within 32-bits.

#include <iostream>
#include <cstdint>

using namespace std;

//start from LSB, use index-based for loop to iterate and keep track of number of 1's using count variable
//return count
class Solution{
public:
    int hammingWeight(uint32_t n){
        int count = 0;
        for (int i = 0; i < 32; i++){
            count += (n & 1);    //if bit is 1, increment count
            n >>= 1;    //shift entire binary number right
        }
        return count;
    }
};

int main(){
    Solution sol;       //object to class
    uint32_t n = 0b00000000000001000001000000100100;
    cout << "The number of 1's is: " << sol.hammingWeight(n) << endl;
    return 0;
}