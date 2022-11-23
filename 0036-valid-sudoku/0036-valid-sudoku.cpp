class Solution {
public:
    
    
        
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> rows(9,vector<int>(9,0));
    vector<vector<int>> cols(9,vector<int>(9,0));
    vector<vector<int>> boxes(9,vector<int>(9,0));
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                {
                    int x = board[i][j]-'0';
                    x--;
                    if(rows[i][x]!=0 || cols[j][x]!=0 || boxes[(i/3)*3+j/3][x]!=0)
                        return false;
                    else
                    {
                        rows[i][x]=1;
                        cols[j][x]=1;
                        boxes[(i/3)*3+j/3][x] = 1;
                    }
                }
            }
        }
        return true;
    }
};