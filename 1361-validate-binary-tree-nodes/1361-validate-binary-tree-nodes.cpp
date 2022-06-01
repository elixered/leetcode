class Solution {
public:
    int counts(vector<vector<int>>& adj, int root)
    {
        int c = 0;
        for(auto i:adj[root])
            c += counts(adj,i);
        return c+1;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            if(l[i]!=-1)
            {
                if(++indegree[l[i]]>1) return false;
                adj[i].push_back(l[i]);
            }
            if(r[i]!=-1)
            {
                if(++indegree[r[i]]>1) return false;
                adj[i].push_back(r[i]);
            }
        }
        int root = -1;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0) root = i;
        }
        if(root==-1) return false;
        if(count(indegree.begin(),indegree.end(),0) > 1) return false;
        if(accumulate(indegree.begin(),indegree.end(),0)!=n-1) return false;
        return counts(adj,root)==n;
    }
};