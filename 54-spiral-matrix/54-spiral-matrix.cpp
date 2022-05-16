class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int rounds = (min(m,n)+1)/2;
        int startRow = 0, endRow = m-1;
        int startCol = 0, endCol = n-1;
        while(rounds--)
        {
            if(startCol>endCol or startRow>endRow)
                break;
            for(int j=startCol; j<=endCol; j++)
            {
                ans.push_back(matrix[startRow][j]);
            }
            startRow++;
            if(startCol>endCol or startRow>endRow)
                break;
            for(int i=startRow; i<=endRow; i++)
            {
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;
            if(startCol>endCol or startRow>endRow)
                break;
            for(int j=endCol; j>=startCol; j--)
            {
                ans.push_back(matrix[endRow][j]);
            }
            endRow--;
            if(startCol>endCol or startRow>endRow)
                break;
            for(int i=endRow; i>=startRow; i--)
            {
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;
            if(startCol>endCol or startRow>endRow)
                break;
        }
        return ans;
    }
};