#Given a string s, find the length of the longest substring without duplicate characters.
#A substring is a contiguous sequence of characters within a string.

from unittest import result


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        left = 0
        result = 0
        
        for right in range(len(s)):
            while s[right] in charSet:
                charSet.remove(s[left])
                left += 1
            charSet.add(s[right])
            result = max(result, right - left + 1)
        return result

print(Solution().lengthOfLongestSubstring("abcabcbb"))