class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty()) return;
        int start = 0, end = s.size() - 1;
        while(start < end){
            char aux = s[start];
            s[start] = s[end];
            s[end] = aux;
            start++, end--;
        }
        
    }
};