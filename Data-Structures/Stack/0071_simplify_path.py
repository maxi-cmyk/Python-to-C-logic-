#stack
class Solution:
    def simplifyPath(self, path: str) -> str:
        #stack to keep track of curr history 
        #split up using /
        components = path.split("/")
        res = []

        for comp in components:
            #ignore
            if comp == "" or comp == ".":
                continue
            #go back if list is not empty
            if comp == "..":
                if res: 
                    res.pop()
            else:
                res.append(comp)
        return "/" + "/".join(res)