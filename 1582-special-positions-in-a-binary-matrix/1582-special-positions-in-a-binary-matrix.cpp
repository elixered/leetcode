class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(row[i]==1 && col[j]==1 && mat[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};