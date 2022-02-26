class Solution {
private:
    int m;
    int n;
    int memo[10][300];
public:
    int match(vector<vector<int>>& stu, vector<vector<int>>& ment, int i, int j)
    {
        int c = 0;
        for(int k=0; k<n; k++)
            if(stu[i][k]==ment[j][k])
                c++;
        return c;
    }
    
    int dfs(vector<vector<int>>& stu, vector<vector<int>>& ment, vector<int>& vis, int curr, int mask)
    {
        if(curr >= m) return 0;
        if(memo[curr][mask]!=-1)
             return memo[curr][mask];
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            if(vis[i]) continue;
            vis[i] = 1;
            ans = max(ans,match(stu,ment,curr,i)+ dfs(stu,ment,vis,curr+1, mask|(1<<i)));
            vis[i] = 0;
        }
        return memo[curr][mask] = ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m = mentors.size();
        n = mentors[0].size();
        memset(memo,-1,sizeof(memo));
        vector<int> vis(m,0);
        return dfs(students,mentors,vis,0,0);
    }
};