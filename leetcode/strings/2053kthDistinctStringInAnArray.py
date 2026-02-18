class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        s = []
        rem = []
        for i in arr:
            if i not in rem:
                s.append(i)
                rem.append(i)
            elif i in s:
                s.remove(i)
        
        cont = 1
        for i in s:
            if cont == k:
                return i
            cont+=1
        
        return ""

        
# Best Solution in C++

# class Solution {
# public:
#     string kthDistinct(vector<string>& arr, int k) {
#         unordered_set<string> distinct, seen;

#         for (const string& s : arr) {
#             if (distinct.count(s)) {
#                 distinct.erase(s);
#                 seen.insert(s);
#             } else if (!seen.count(s)) {
#                 distinct.insert(s);
#             }
#         }

#         for (const string& s : arr) {
#             if (distinct.count(s)) {
#                 k--;
#                 if (k == 0) {
#                     return s;
#                 }
#             }
#         }

#         return "";
#     }
# };