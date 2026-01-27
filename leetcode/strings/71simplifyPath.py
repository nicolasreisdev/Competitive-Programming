class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.split('/')
        ans = []
        for signal in path:
            if signal == '' or signal == '.' or signal == '':
                continue
            elif signal == '..':
                ans = ans[:len(ans)-1]
            else:
                ans.append(f"/{signal}")
        if len(ans) == 0:
            return "/"
        res = ""
        for path in ans:
            res += path
        return res