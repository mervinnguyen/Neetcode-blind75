#You are given an integer array prices where prices[i] is the price of NeetCoin on the 
#ith day.

#You may choose a single day to buy NeetCoin and choose a different day in the future to sell it.

#Return the maximum profit you can achieve. You may choose to not make any transactions, in whuch case the profit would be 0.

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        #Use a nested for loop to iterate through all possible indices
        #keep track of maximum profit using maxProf
        maxProf = 0
        for i in range(len(prices)):
            for j in range(i+1, len(prices)):
                maxProf = max(maxProf, prices[j] - prices[i])
        return maxProf

print(Solution().maxProfit([1,5,3,6,4]))