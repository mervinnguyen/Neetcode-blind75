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
        if not s:
            return []
        sizes = []
        result = []
        i = 0

        while s[i] != "#":
            current = " "
            while s[i] != ",":
                current += s[i]
                i += 1
            sizes.append(int(current))
            i += 1
        i += 1  # skip the '#'
        for size in sizes:
            result.append(s[i:i + size])
            i += size
        return result
    
    
    