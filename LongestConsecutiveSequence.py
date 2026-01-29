#Given an array of integers nums, returnt the length of the longest consecutive sequence of elements that can be formed.
#A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than
#the previous element. The elements do not have to be consecutive in the original array. 

#You must write an algorithm that runs in O(n) time. 

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        #use a hashset to identify duplicates, declare result
        #iterate through each nums, while the current number (0) in nums, increment streak and current
        #res = max(res, streak)
        hashSet = set(nums)
        result = 0
        for num in nums: 
            current = nums
            streak = 0
            while current in hashSet:
                current += 1
                streak += 1
            result = max(result, streak)
        return result