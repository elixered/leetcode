typedef pair<int,int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n);
        for(auto it:times)
        {
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        vector<int> minDist(n,1e6);
        minDist[k-1] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();
            for(auto nb:adj[node]){
                int next = nb.first;
                int weight = nb.second;
                if(minDist[next] > dist+weight){
                    minDist[next] = dist+weight;
                    pq.push({minDist[next],next});
                }
            }
        }
        for(auto it:minDist)
            if(it == 1e6) return -1;
        return *max_element(minDist.begin(),minDist.end());
    }
};