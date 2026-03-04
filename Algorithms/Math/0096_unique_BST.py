#math 

class Solution:
    def numTrees(self, n: int) -> int:
        #how many unqiue ways -> dp, return dp[n] 
        #catalan numbers

        #assign 1 to n+1 sections
        uniq_tree = [1] * (n+1)

        #since dp[0] and dp[1] is 1, we start from 2 
        for nodes in range(2, n+1):
            total = 0
            for root in range(1, nodes + 1):
                #total = left * right -> (i-1) * (n-i)
                total += uniq_tree[root-1] * uniq_tree[nodes-root]
            uniq_tree[nodes] = total 
        return uniq_tree[n]


