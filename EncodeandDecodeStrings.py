#Design an algorithm to encode a list of strings to a string. The
#encoded string is then sent over the network and is decoded back to the original list of strings



class Solution: 
    def encode(self, strs: List[str]) -> str:
        if not strs:
            return " "
        sizes = []
        for string in strs:
            sizes.append(len(string))
        result = " "
        for size in sizes:
            result = str(size) + ","
        result += "#"
        for s in strs:
            result += s
        return result
    
    def decode(self, strs: List[str]) -> str:
        