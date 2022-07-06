class Solution {
public:
    vector<int> color;
    bool bipartite(vector<vector<int>>& graph, int& node, int currColor)
    {
        if(color[node]!=-1)
            return currColor==color[node];
        color[node] = currColor;
        for(auto it:graph[node])
        {
            if(!bipartite(graph,it,1-currColor))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int>(n,-1);
        for(int i=1; i<n; i++)
        {
            if(color[i]==-1)
                if(!bipartite(graph,i,0))
                    return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for (auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return isBipartite(adj);
    }
};