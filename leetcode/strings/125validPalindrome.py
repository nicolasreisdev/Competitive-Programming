# My Solution

class Solution:
    def isPalindrome(self, s: str) -> bool:
        ans = ""
        for letter in s:
            if letter.isalnum():
                ans += letter.lower()

        return ans == ans[::-1]


# Best Solution O(1) Space COmplexity in C++

# class Solution {
# public:
#     bool isPalindrome(string s) {
#         int l = 0, r = s.length() - 1;

#         while (l < r) {
#             while (l < r && !alphaNum(s[l])) {
#                 l++;
#             }
#             while (r > l && !alphaNum(s[r])) {
#                 r--;
#             }
#             if (tolower(s[l]) != tolower(s[r])) {
#                 return false;
#             }
#             l++; r--;
#         }
#         return true;
#     }

#     bool alphaNum(char c) {
#         return (c >= 'A' && c <= 'Z' ||
#                 c >= 'a' && c <= 'z' ||
#                 c >= '0' && c <= '9');
#     }
# };