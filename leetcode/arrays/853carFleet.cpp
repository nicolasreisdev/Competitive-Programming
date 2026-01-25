class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        // sort in descending order
        sort(pair.rbegin(), pair.rend());

        int fleets = 1;
        // the equation of the more near to target 
        double prevTime = (double)(target - pair[0].first) / pair[0].second;

        for (int i = 1; i < n; i++) {
            // the current car equation
            double currTime = (double)(target - pair[i].first) / pair[i].second;
            // if the currtime is greater than the more near to target
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};