class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m+n==0)
            return 1;
        vector<int> col(n+1,0);
        col[1] = 1;
        for(int i=1; i<=m; i++)
        {
            vector<int> curr(n+1,0);
            for(int j=1; j<=n; j++)
            {
                curr[j] = col[j]+curr[j-1];
            }
            col = curr;
        }
        return col[n];
    }
};