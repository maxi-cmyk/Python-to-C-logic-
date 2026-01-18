#backtracking
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        comb = []

        def dfs(start):
            if len(comb) == k: #correct size
                res.append(comb[:]) 
                return 

            # Recursive Step
            need = k - len(comb) #prune away unfinished combos
            for i in range(start, n - need + 2):
                #last possible starting number = n -(k-len(comb)) + 1
                #hence index is n-need + 2
                comb.append(i)
                dfs(i + 1)  
                comb.pop()  # Backtrack step: clean up for the next loop
        
        dfs(1)
        return res