#You are given an integer array prices where prices[i] is the price of NeetCoin on the 
#ith day.

#You may choose a single day to buy NeetCoin and choose a different day in the future to sell it.

#Return the maximum profit you can achieve. You may choose to not make any transactions, in whuch case the profit would be 0.

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #Use a nested for loop to iterate through all possible indices
        #keep track of maximum profit using maxProf