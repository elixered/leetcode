class Solution {
public:
    
    int dfs(vector<vector<int>>& adj, vector<int>& quiet, vector<int>& ans, int node) {
        if(ans[node] != -1) return ans[node];
        
        ans[node] = node;
        for(auto& nb : adj[node]) {
            int curr = dfs(adj, quiet, ans, nb);
            
            if(quiet[curr] < quiet[ans[node]]) {
                ans[node] = curr;
            }
        }
        
        return ans[node];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        
        vector<vector<int>> adj(n);

        for(auto& rich : richer) {
            adj[rich[1]].push_back(rich[0]);
        }
        
        vector<int> answer(n, -1);
        
        for(int i=0; i<n; i++) {
            if(answer[i] == -1)
                dfs(adj, quiet, answer, i);
        }
        
        return answer;
    }
};