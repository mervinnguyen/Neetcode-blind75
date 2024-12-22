#Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

#An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

class Solution: 
    def isAnagram(self, s: str, t: str) -> bool:
        #hash table for strings s and t
        hashS = {}
        hashT = {}
        s = sorted(s)
        print(s)

#test case
if __name__ == "__main__":
    s = "anagram"
    t = "nagaram"
    sol = Solution()
    print(sol.isAnagram(s, t)) 