#Given an integer array nums and an integer k, return the k most frequent elements
#within the array

#Example 1:
#Input: nums = [1,2,2,3,3,3], k =2
#Output: [2,3]

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    #Count the frequency of each indice in the list and increment as the number appears

    #Hashmap to keep track of the frequency of each number
    frequency = {}

    #iterate through each index of num and the frequency
    for n in nums:
        frequency[n] = frequency.get(n, 0) + 1
    
    #Now that frequency = {1:1, 2:2, 3:3}

    #Sort in array in this order (frequency, nums)
    array = []
    for nums, freq in frequency.items():
        array.append((freq, nums))
    array.sort()

    inc = 0
    result = []
    while inc < k:
        result.append(array.pop()[1])
        inc += 1
    
    return result

