class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int c = 0;
        unordered_map<int,int> mp;
        for(int colstart=0; colstart<n; colstart++)
        {
            for(int colend=colstart; colend<n; colend++)
            {
                mp = {{0,1}};
                int sum = 0;
                for(int row=0; row<m; row++)
                {
                    sum += matrix[row][colend];
                    if(colstart>0)
                        sum -= matrix[row][colstart-1];
                    c += mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return c;
    }
};