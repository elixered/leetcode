class Solution {
public:
    
    
    
    vector<int> count;
    vector<int> res;
    vector<vector<int>> adj;
    
    void dfs1(int x, int par){
        for(auto i:adj[x]){
            if(i==par) continue;
            dfs1(i,x);
            count[x] += count[i];
            res[x] += res[i] + count[i];
        }
    }
    
    void dfs2(int x, int par){
        for(auto i:adj[x]){
            if(i==par) continue;
            //consider other half
            int otherHalfSum = res[x] - res[i] - count[i];
            int otherHalfCount = count.size() - count[i];
            res[i] += otherHalfSum + otherHalfCount;
            dfs2(i,x);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        count.resize(n,1);
        res.resize(n,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return res;
    }
};