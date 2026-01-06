#two_pointers
class Solution:
    def compress(self, chars: List[str]) -> int:
        #counting consecutive occurances, return total 
        i = 0
        write = 0
        while i < len(chars):
            char = chars[i]
            count = 0
            while i < len(chars) and chars[i] == char:
                count+=1
                i+=1
            chars[write] = char
            write+=1

            if count > 1:
                for freq in str(count): #12 -> "1", "2"
                    chars[write] = freq
                    write+=1
        return write
        