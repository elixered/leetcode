class Solution {
public:
    bool matched(vector<int>& a, vector<int>& b)
    {
        return a==b;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mp0(m),mp1(m);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                    mp0[i].push_back(j);
                else mp1[i].push_back(j);
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            int zero = 0, one = 0;
            for(int j=0; j<m; j++)
            {
                if(matched(mp0[i],mp0[j]) or matched(mp0[i],mp1[j]))
                    zero++;
                if(matched(mp1[i],mp0[j]) or matched(mp1[i],mp1[j]))
                    one++;
            }
            ans = max({ans,zero,one});
        }
        return ans;
    }
};