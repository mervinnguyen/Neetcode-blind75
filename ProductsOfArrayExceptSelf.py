#Given an array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
#Each product is guaranteed to fit in a 32-bit integer.
#Follow-up: Could you solve it in O(n) time without using the division operation?

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)   #get the length of the input array
        res = [0]*n     #create a result array to store product values with n length

        for i in range(n):
            prod = 1    #initialize product variable to 1
            for j in range(n):
                if i != j:
                    prod *= nums[j]
            res[i] = prod   #store the product value in the result array at index i
        
        return res
