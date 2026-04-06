#backtracking

#solution is good, but slow because checking for doomed branches 
#eg -> put 1 item, 10 left, max 3 for 3 boxes, 10 != 9
#look at pruning lines, add those for speeeeed 

class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s) < 4 or len(s) > 12: #prune 1
            return []
        
        n = len(s)
        res = []

        def backtrack(i, curr, seg):
            if seg == 4:
                #success, 4 segments done 
                if i == n: 
                    res.append(".".join(curr))
                return #prune 2
            
            chars_left = n - i
            max_capacity_left = (4-seg) * 3
            if chars_left > max_capacity_left: #prune 3
                return
            
            #check every 3 chars (max)
            for j in range(i, min(i+ 3), n):
                sub = s[i: j +1]
                    
                 #check leading zeroes
                if len(sub) > 1 and sub[0] == '0':
                    break
                    
                #valid int <= 255
                if int(sub) <= 255:
                    curr.append(sub)
                    backtrack(j+1, curr, seg + 1)
                    
                    #remove used element, backtrack
                    curr.pop()
                    
        backtrack(0, [], 0)

        return res