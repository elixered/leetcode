class Solution {
public:
    
     
    void unplace_queen( vector<string> &board, vector<int> &left, vector<int> &dia1, vector<int> &dia2, int row,int col)
    {
        board[row][col] = '.';
        left[row]=0;
        dia1[row+col]=0;
        dia2[left.size()-1+col-row]=0;
    }
    
    void place_queen( vector<string> &board, vector<int> &left, vector<int> &dia1, vector<int> &dia2, int row,int col)
    {
        board[row][col] = 'Q';
        left[row]=1;
        dia1[row+col]=1;
        dia2[left.size()-1+col-row]=1;
    }
    
    bool safe(vector<int> &left, vector<int> &dia1, vector<int> &dia2, int row,int col)
    {
        return (left[row]==0 && dia1[row+col]==0 && dia2[left.size()-1+col-row]==0);
    }
    
    void solve(vector<vector<string>> &ans, vector<string> &board, vector<int> &left, vector<int> &dia1, vector<int> &dia2, int col,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(safe(left,dia1,dia2,row,col))
            {
                place_queen(board,left,dia1,dia2,row,col);
                solve(ans,board,left,dia1,dia2,col+1,n);
                unplace_queen(board,left,dia1,dia2,row,col);
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {   
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
       
        vector<int> left(n,0), dia1(2*n-1,0), dia2(2*n-1,0);
        solve(ans,board,left,dia1,dia2,0,n);
        return ans;
    }
};