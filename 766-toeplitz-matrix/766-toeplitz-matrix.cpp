class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++)
        {
            int curr = matrix[i][0];
            int j = i;
            int k = 0;
            while(j<m && k<n)
            {
                if(curr!=matrix[j][k]) return false;
                j++;
                k++;
            }
        }
        for(int j=0; j<n; j++)
        {
            int curr = matrix[0][j];
            int row = 0;
            int col = j;
            while(row<m && col<n)
            {
                if(curr!=matrix[row][col]) return false;
                row++;
                col++;
            }
        }
        return true;
    }
};