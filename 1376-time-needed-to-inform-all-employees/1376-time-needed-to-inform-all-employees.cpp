class Solution {
public:
    vector<vector<int>> adj;
    int maxtime(int node, vector<int>& time)
    {
        int curr = 0;
        for(auto i:adj[node])
        {
            curr = max(maxtime(i,time),curr);
        }
        return curr+time[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj = vector<vector<int>>(n);
        for(int i=0; i<n; i++)
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        return maxtime(headID,informTime);
    }
};