#include <bits/stdc++.h>
using namespace std;


class Solution {

public:

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};
        
        vector<pair<int, int>> events;
        
        for(auto b: buildings){
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        
        sort(events.begin(), events.end());
        
        int ongoingHeight = 0;
        
        // points.first = x coordinate, points.second = height
        for(int i = 0; i < events.size(); i++){
            int currentPoint = events[i].first;
            int heightAtCurrentPoint = events[i].second;
            
            if(heightAtCurrentPoint < 0){
                pq.insert(-heightAtCurrentPoint);
            } else {
                pq.erase(pq.find(heightAtCurrentPoint));
            }
            
            // after inserting/removing heightAtI, if there's a change
            auto pqTop = *pq.rbegin();
            if(ongoingHeight != pqTop){
                ongoingHeight = pqTop;
                ans.push_back({currentPoint, ongoingHeight});
            }
        }
        
        return ans;
    }
};