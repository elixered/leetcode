class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mins(m,INT_MAX);
        vector<int> maxs(n,INT_MIN);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                mins[i] = min(mins[i],matrix[i][j]);
            }
        }
        for(int j=0; j<n; j++)
        {
            for(int i=0; i<m; i++)
            {
                maxs[j] = max(maxs[j],matrix[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == mins[i] && mins[i]==maxs[j])
                    ans.push_back(mins[i]);
            }
        }
        return ans;
    }
};