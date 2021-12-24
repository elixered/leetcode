class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
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
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            n--;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return 0==n;
    }
};