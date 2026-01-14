# Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

# An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

# Example 1:

# Input: strs = ["act","pots","tops","cat","stop","hat"]

# Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
# Example 2:

# Input: strs = ["x"]

# Output: [["x"]]
# Example 3:

# Input: strs = [""]

# Output: [[""]]

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        dict = {}
        for s in strs:
            sortedS = ''.join(sorted(s))
            if sortedS not in dict:
                dict[sortedS] = []  #create an empty list for anagram key
            dict[sortedS].append(s)  #append the original string to the dictionary value corresponding to the anagram
        
        return list(dict.values())    #return the list of anagram groups as a list of lists
    
#test cases
strs = ["act","pots","tops","cat","stop","hat"]
sol = Solution()
print(sol.groupAnagrams(strs))