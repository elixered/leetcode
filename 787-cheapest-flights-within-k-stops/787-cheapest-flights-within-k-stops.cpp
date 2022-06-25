class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int inf = pow(10,9);
        vector<int> dist(n,inf);
        dist[src] = 0;
        for(int i=0; i<=k; i++){
            vector<int> curr = dist;
            for(auto& f:flights){
                curr[f[1]] = min(curr[f[1]],dist[f[0]]+f[2]);
            }
            dist = curr;
        }
        return dist[dst] == inf ? -1:dist[dst];
    }
};