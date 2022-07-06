class Solution {
public:
    
    pair<int,int> minDist(vector<vector<int>>& adj, int i){
        vector<int> dist(adj.size(),1e8);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
             int m = q.size();
            while(m--){
                auto f = q.front();
                q.pop();
                for(auto nb:adj[f]){
                    if(dist[nb] > dist[f]+1){
                        dist[nb] = dist[f]+1;
                        q.push(nb);
                    }
                }
            }
        }
        int first=0,second=0;
        for(int i=1; i<adj.size(); ++i){
            if(dist[i] > dist[first]){
                first = i;
            }
        }
        return {first,dist[first]};
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        if(n==1) return 0; 
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto [f,d] = minDist(adj,0);
        auto [node,ans] = minDist(adj,f);
        return ans;
    }
};