class Solution {
public:
    
    pair<int,int> solve(vector<vector<int>>& adj, vector<int>& val, int node){
        int nodes=1,rank=val[node];
        for(auto nb:adj[node]){
            auto [num,sum] = solve(adj,val,nb);
            nodes += num;
            rank += sum;
        }
        if(rank == 0)
            return {0,0};
        else
            return {nodes,rank};
    }
    
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; ++i){
            if(parent[i] != -1)
                adj[parent[i]].push_back(i);
        }
        return solve(adj,value,0).first;
    }
};