class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color, int pcolor){
        color[node] = 1-pcolor;
        for(auto nb:graph[node]){
            if(color[nb]==-1){
                if(dfs(graph,nb,color,1-pcolor)==false)
                    return false;
            }
            else if(color[nb] == 1-pcolor)
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0; i<graph.size(); ++i){
            if(color[i] == -1){
                if(dfs(graph,i,color,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};