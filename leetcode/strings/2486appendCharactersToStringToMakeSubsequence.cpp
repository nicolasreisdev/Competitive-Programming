class Solution {
public:
    int appendCharacters(string s, string t) {
        int maxLetters = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i] == t[maxLetters]) maxLetters++;
        }
        return t.size() - maxLetters;
    }
};