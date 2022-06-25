class Solution {
public:
    
    bool dfs(string src, string dst, unordered_set<string>& visited, double& val){
        if(!adj.count(src) or !adj.count(dst)) return false;
        if(src == dst) return true;
        for(auto nb:adj[src]){
            if(visited.count(nb.first)) continue;
            visited.insert(nb.first);
            double prev =  val;
            val *= nb.second;
            if(dfs(nb.first,dst,visited,val))
                return true;
            val = prev;
        }
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        for(int i=0; i<n; i++){
            string num = equations[i][0];
            string deno = equations[i][1];
            double val = values[i];
            adj[num][deno] = val;
            adj[deno][num] = (1.0)/val;
        }
        vector<double> ans;
        for(auto q:queries){
            double value = 1.0;
            unordered_set<string> vis;
            if(dfs(q[0],q[1],vis,value))
                ans.push_back(value);
            else ans.push_back(-1);
        }
        return ans;
    }
private:
    unordered_map<string,unordered_map<string,double>> adj;
};