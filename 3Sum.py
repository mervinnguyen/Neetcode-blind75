#Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where 
#nums[i] + nums[j] + nums[k] == 0, and the indices i,j, and k are all distinct
#The output should not contain any duplicate triplets in any order.

class Solution:
    def threeSum(self, nums: list[int]) -> List[List[int]]:
        result = []
        nums.sort()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                for k in range(j+1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        temp = [nums[i],nums[j],nums[k]]
                        result.append(temp)
        return result