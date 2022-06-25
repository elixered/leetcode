class Solution {
public:
    typedef pair<double,int> ppi;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<ppi>> adj(n);
        int idx = 0;
        for(auto& e:edges){
            adj[e[0]].push_back({succProb[idx],e[1]});
            adj[e[1]].push_back({succProb[idx++],e[0]});
        }
        
        vector<double> prob(n,0);
        vector<bool> vis(n,false);
        prob[start] = 1;
        priority_queue<ppi> pq;
        pq.push({prob[start],start});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            double probab = curr.first;
            int node = curr.second;
            if(vis[node]) continue;
            vis[node] = true;
            if(node==end) return probab;
            for(auto nb:adj[node]){
                int child = nb.second;
                double w = nb.first;
                if(!vis[child] && w*probab > prob[child]){
                    prob[child] = w*probab;
                    pq.push({w*probab,child});
                }
            }
        }
        return prob[end];
    }
};