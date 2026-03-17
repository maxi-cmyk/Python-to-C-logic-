#dp

#time complexity -> o(m * n)
#space complexity -> o(min (m,n), because its an optimised dp array 

class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        #some dp nonsense 
        # dp[j] if s3[i+j-1] = s1[i-1] interweave s2[j-1]
        m, n = len(s1), len(s2)
        if (m + n) != len(s3):
            return False 
        dp = [False] * (n+ 1)
        dp[0] = True 

        for j in range(1, n+1):
            #check if the previous is true, then check if s2 and s3 overlap
            #do this so we know which part of s3 begins with which part of s2? 
            dp[j] = dp[j-1] and s2[j-1] == s3[j-1]

        for i in range(1, m+1):
            #every first instance must match 
            dp[0] = dp[0] and s1[i-1] == s3[i-1]
            for j in range(1, n + 1):
                #use or in case there is concesuctive 
                dp[j] = (dp[j] and s1[i-1] == s3[i+j-1]) or \
                        (dp[j-1] and s2[j-1] == s3[i + j - 1])
        return dp[n]