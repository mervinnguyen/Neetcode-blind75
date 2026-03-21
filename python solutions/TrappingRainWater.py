#You are given an array of non-negative integers height which represent and elevation map
#Each value height[i] represents the height of a bar, which has a width of 1.

#Return the maximum area of water that can be trapped between the bars.

class Solution:
    def trap(self, height: List[int]) -> int:
        #Two pointer approach
        left = 0
        right = len(height) - 1
        #track leftMax and rightMax as the tallest walls seen
        leftMax = height[left]
        rightMax = height[right]
        result = 0
        while left < right:
            if leftMax < rightMax:
                left += 1
                leftMax = max(leftMax, height[left])
                result += leftMax - height[left]
            else:
                right -= 1
                rightMax = max(rightMax, heigh[right])
        return result