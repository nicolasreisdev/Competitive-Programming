class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m; // f = letter, s = amount
        for(int i = 0; i < text.size();i++)m[text[i]]++;
        int ans = text.size()/7;
        ans = min(ans, m['b']);
        ans = min(ans, m['a']);
        int letterL = floor(m['l']/2);
        ans = min(ans, letterL);
        int letterO = floor(m['o']/2);
        ans = min(ans, letterO);
        ans = min(ans, m['n']);
        return ans;
    }
};