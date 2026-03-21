#Title: Contains Duplicate

# Given an integer array nums, return true if any value appears more than once in the array, otherwise return false. 

class Solution:
    #function to track duplicates
    #paramenter: nums: List[int] -> true or false
    def hasDuplicate(self, nums: List[int]) -> bool: 
        hashmap = {}
        for i in nums:
            if i in hashmap:
                return True    #iterate through each integer in nums, if the integer is in hashmap, return 
            #add integer to hashmap
            hashmap[i] = 1 #add key-value pair to hashmap for integer in array
        return False

#Explanation:
# 1) Create emtpty hashmap
# 2) Iterate through each num in nums
# 3) If the num is in hashmap, return True. If not, add 1 to hashmap
# 4) Iterate through all nums, if not duplicates found, return False