class Solution {
public:
    bool isValid(string s) {
        stack<char> filo;
        map<char, char> mappingValues = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for(int i = 0; i < s.size();i++){
            if(mappingValues.count(s[i])){
                if(!filo.empty() and mappingValues[s[i]] == filo.top()) filo.pop();
                else return false;
            }
            else filo.push(s[i]);
        }
        return filo.empty();
    }
};