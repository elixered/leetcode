class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rowsize = rowSum.size();
        int colsize = colSum.size();
        vector<vector<int>> ans(rowsize,vector<int>(colsize,0));
        for(int i=0; i<rowsize; i++)
        {
            int currsum = 0;
            int reqsum = rowSum[i];
            for(int j=0; j<colsize; j++)
            {
                if(currsum<reqsum)
                {
                    int x = min(colSum[j],reqsum-currsum);
                    currsum += x;
                    ans[i][j] = x;
                    colSum[j] -= x;
                }
            }
        }
        return ans;
    }
};