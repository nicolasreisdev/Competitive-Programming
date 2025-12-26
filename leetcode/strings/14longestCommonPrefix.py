class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        sortingList = sorted(strs, key=len)
        ans = sortingList[0]
        for string in sortingList:
            for i, value in enumerate(string):
                if len(ans)-1 < i:
                    break
                elif ans[i]!=string[i]:
                    ans = string[:i]
        
        return ans
                