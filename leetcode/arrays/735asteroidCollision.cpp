// My Solution

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> query;
        bool add;
        for(int i = 0; i < asteroids.size();i++){
            if(asteroids[i] > 0) query.push_back(asteroids[i]);
            else{
                add = true;
                while(!query.empty() and query.back() > 0){
                    int value = query.back();
                    if(abs(asteroids[i]) > value){
                        query.pop_back(), add = true;
                    }
                    else if(abs(asteroids[i]) == value) {
                        query.pop_back(), add = false;
                        break;
                    }
                    else{
                        add = false;
                        break;
                    }
                }
                if(add)query.push_back(asteroids[i]);
            }
        }
        return query;
    }
};