#Given an array of integers numbers that is sorted in non-decreasing order
#Return the indices (1-indexed) of two numbers, [index1, index2], such that
#they add up to a given target number target and index1 < index2.
#Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
#There will always be exactly one valid solution.
#Your solution must use O(1) additional space.

class Solution: 
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        #Start left pointer on the first index
        #right pointer at the last index
        #compare two values, if sum > target, decrement right pointer, if sum < target, decerement pointer
        left = 0
        right = len(numbers) - 1
        result = []
        while (left < right):
            sum = numbers[left] + numbers[right]

            if sum == target:
                result.append(numbers[left])
                result.append(numbers[right])
                return result
            if sum > target:
                right -= 1
            if sum < target:
                left += 1

#Test case
solution = Solution()
print(solution.twoSum([2,7,11,15], 9)) #[2,7]