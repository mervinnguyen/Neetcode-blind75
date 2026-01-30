#Given a string s, return true if it a palindrome, otherwise return false
#A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores al non-alphanumeric characters.

class Solution:
    def isPalindrome(self, s: str) -> bool:
        #Two pointer approach
        #Set left pointer at the first index, right pointer at the last index
        #Compare each pointer, bring it closer to each other until it hits the middle
        left = 0
        right = len(s) - 1

        while (left < right):
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right += 1

            if s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        return True