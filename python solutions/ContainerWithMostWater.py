#You are given an integer array heights where heights[i] represents the height of the ith bar.
#You may choose any two bars to form a container. Return the maximum amount of water a container can store.

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        result = 0
        while left < right:
            #calculate the current area
            area = min(heights[left], heights[right]) * (right - left)
            result = max(result, area)  #set the result to the current max outcome

            if heights[left] <= heights[right]:
                left += 1
            else:
                right -= 1
        return result