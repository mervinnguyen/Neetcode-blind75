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