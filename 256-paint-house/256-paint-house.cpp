class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> prev(3,0);
        for(int i=0; i<costs.size(); ++i){
            vector<int> curr(3,INT_MAX);
            curr[0] = min(prev[1],prev[2])+costs[i][0];
            curr[1] = min(prev[0],prev[2])+costs[i][1];
            curr[2] = min(prev[0],prev[1])+costs[i][2];
            prev = curr;
        }
        return min({prev[0],prev[1],prev[2]});
    }
};