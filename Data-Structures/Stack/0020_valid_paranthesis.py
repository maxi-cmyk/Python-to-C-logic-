#stack
class Solution:
    def isValid(self, s: str) -> bool:
        a = []
        for i in range (len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                a.append(s[i]) #push to end of list
            else: 
                if not a:
                    return False
                top = a.pop() #remove from list
                if s[i]==')'and top!='(':
                    return False
                if s[i]==']'and top!='[':
                    return False
                if s[i]=='}'and top!='{':
                    return False
        return len(a)==0