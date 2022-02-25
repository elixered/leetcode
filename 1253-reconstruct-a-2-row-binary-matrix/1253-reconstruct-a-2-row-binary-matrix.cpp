class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2,vector<int>(n,0));
        for(int j=0; j<n; j++)
        {
            if(colsum[j]==0)
                continue;
            if(colsum[j]==1)
            {
                if(upper>=lower)
                {
                    upper--;
                    if(upper<0) return {};
                    ans[0][j] = 1;
                }
                else
                {
                    lower--;
                    if(lower<0) return {};
                    ans[1][j] = 1;
                }
            }
            else
            {
                upper--;
                lower--;
                if(upper<0 or lower<0) return {};
                ans[0][j] = 1;
                ans[1][j] = 1;
            }
        }
        if(upper>0 or lower>0) return {};
        return ans;
    }
};