#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 1; i < points.size();i++){
            int timeX, timeY;
            timeX = abs(points[i-1][0] - points[i][0]);
            timeY = abs(points[i-1][1] - points[i][1]);
            time += max(timeX, timeY);
        }
        return time;
    }
};