class Solution:
    def readBinaryWatch(self, turnedOn: int) -> list[str]:
        if turnedOn == 0:
            return ["0:00"]
        if turnedOn > 8:
            return []  # Max valid LEDs: 3 (hours <= 11) + 5 (mins <= 59) = 8

        mask = (1 << 6) - 1
        q = (1 << turnedOn) - 1
        limit = q << (10 - turnedOn)
        res = []

        while q <= limit:
            mins = q & mask
            hour = q >> 6
            if hour < 12 and mins < 60:
                res.append(f"{hour}:{mins:02d}")

            # Gosper's advancement must run unconditionally on every loop
            r = q & -q
            n = q + r
            q = (((q ^ n) // r) >> 2) | n

        return res
    
    
class Solution(object):
    def readBinaryWatch(self, turnedOn):
        if turnedOn < 0 or turnedOn > 10:
            return []
        
        result = []
        for h in range(12):
            for m in range(60):
                if bin(h).count('1') + bin(m).count('1') == turnedOn:
                    result.append("{}:{:02d}".format(h, m))
        
        return result