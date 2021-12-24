class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(numCourses,0);
        queue<int> q;
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i=0; i<n; i++)
            if(indegree[i]==0)
                q.push(i);
        vector<int> ans;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    
    }
};