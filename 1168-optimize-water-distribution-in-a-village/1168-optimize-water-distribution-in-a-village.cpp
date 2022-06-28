class Solution {
public:
    typedef pair<int,int> ppi;
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<ppi>> adj(n+1);
        for(auto& pipe : pipes){
            adj[pipe[0]].push_back({pipe[1],pipe[2]});
            adj[pipe[1]].push_back({pipe[0],pipe[2]});
        }
        for(int i=1; i<=n; i++){
            adj[0].push_back({i,wells[i-1]});
        }
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        vector<int> mstSet(n+1,0);
        vector<int> minDist(n+1,INT_MAX);
        minDist[0] = 0;
        pq.push({0,0});
        int size = 0;
        int cost = 0;
        while(!pq.empty()){
            auto w = pq.top().first;
            auto u = pq.top().second;
            pq.pop();
            if(mstSet[u]) continue;
            mstSet[u] = 1;
            cost += w;
            size++;
            for(auto nb:adj[u]){
                int v = nb.first;
                int weight = nb.second;
                if(mstSet[v]==0 ){
                    pq.push({weight,v});
                }
            }
        }
        return cost;
    }
};