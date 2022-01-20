class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dir = 0;
        int rowStart = 0, rowEnd = m-1;
        int colStart = 0, colEnd = n-1;
        vector<int> ans;
        while(rowStart<=rowEnd  && colStart<=colEnd)
        {
            switch(dir)
            {
                case 0:
                    for(int col=colStart; col<=colEnd; col++)
                        ans.push_back(grid[rowStart][col]);
                    rowStart++;
                    dir = 1;
                    break;
                case 1:
                    for(int row=rowStart; row<=rowEnd; row++)
                        ans.push_back(grid[row][colEnd]);
                    colEnd--;
                    dir = 2;
                    break;
                case 2:
                    for(int col=colEnd; col>=colStart; col--)
                        ans.push_back(grid[rowEnd][col]);
                    rowEnd--;
                    dir = 3;
                    break;
                case 3:
                    for(int row=rowEnd; row>=rowStart; row--)
                        ans.push_back(grid[row][colStart]);
                    colStart++;
                    dir = 0;
                    break;
            }
        }
        return ans;
    }
};