class Solution:
    def decodeString(self, s: str) -> str:
        string = []
        number = []
        ans = ""
        idx = 0

        for c in s:
            if c.isdigit():
                idx = idx * 10 + int(c)
            elif c == "[":
                string.append(ans)
                number.append(idx)
                ans = ""
                idx = 0
            elif c == "]":
                temp = ans
                ans = string.pop()
                count = number.pop()
                ans += temp * count
            else:
                ans += c

        return ans