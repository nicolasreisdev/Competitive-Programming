class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;
        int cont = 0;
        for(int i = 0; i  < allowed.size();i++)s.insert(allowed[i]);
        for(int i = 0; i < words.size();i++){
            int flag = false;
            for(int j = 0; j < words[i].size();j++){
                if(s.find(words[i][j]) == s.end()){
                    flag = true;
                    break;
                }
            }
            if(!flag)cont++;
        }
        return cont;
    }
};