class Solution:
    #Thought process:
    # We wnat the longest stretch of characters where, after changing at most k of elements in the string, they can all become the same.
    # Data Structure: Sliding Window iterating through the string [left, right]
    # For the current sliding window that we create:
    #   1) Count how many times each character appears
    #   2) Find the most frequent character count maxFreq in the window.
    #   3) Check the number of changes needed to make the whole window equal to that char = window_length - maxFreq

    #If this is greater than our current k element, the window is invalid:
    #Shrink it from the left unril it becomes valid again.
    #While sliding, keep track of the largest valid window again.
    #The largest window size is the answer.
    def characterReplacement(self, s: str, k: int) -> int:
        #dictionary to store each count of character in the current window
        count = {}

        left = 0 #left pointer
        max_freq = 0    #highest frequency of a single character in the window
        result = 0      #length of the longest valid window

        #Expand the window by moving "right"
        for right in range(len(s)):
            char = s[right]

            #Increase count of the current character
            count[char] = count.get(char, 0) + 1

            #Update the max frequency seen in the current window
            max_freq = max(max_freq, count[char])

            #Current window size
            window_size = right - left + 1

            #If the number of chars to change exceeds k, shrink the window from the left
            #changes needed = window_size - max_freq
            while window_size - max_freq > k:
                left_char = s[left]
                count[left_char] -= 1   #Character at "left" is leaving the window
                left += 1
                window_size = right - left + 1 #update window size 

            #Update the result with the maximum valid window size found so far
            result = max(result, window_size)
        
        #The result is teh length of the longest substring we can make repeating
        return result
    
sol = Solution()
print(sol.characterReplacement("XYYX", 2))