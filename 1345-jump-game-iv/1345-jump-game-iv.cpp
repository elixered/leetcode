class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<2)
            return 0;
        unordered_map<int,vector<int>> graph;
        for(int i=0; i<n; i++)
            graph[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,0);
        visited[0] = 1;
        int jumps = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto curr = q.front();
                q.pop();
                if(curr==n-1) return jumps;
                visited[curr] = 1;
                if(curr-1>=0 && !visited[curr-1])
                {
                    q.push(curr-1);
                    visited[curr-1] = 1;
                }
                if(curr+1<n && !visited[curr+1])
                {
                    q.push(curr+1);
                    visited[curr+1] = 1;
                }
                for(auto& it:graph[arr[curr]])
                {
                    if(!visited[it])
                        q.push(it);
                }
                graph[arr[curr]] = {};
            }
            jumps++;
        }
        return -1;
    }
};