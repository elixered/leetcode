class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int r,c;
        for(int i=0; i<m; i++)
        {
            bool f = false;
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='R')
                {
                    r = i;
                    c = j;
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        int ans = 0;
        for(int i=r+1; i<m; i++)
        {
            if(board[i][c]=='B')
                break;
            if(board[i][c]=='p')
            {
                ans++;
                break;
            }
        }
        for(int i=r-1; i>=0; i--)
        {
            if(board[i][c]=='B')
                break;
            if(board[i][c]=='p')
            {
                ans++;
                break;
            }
        }
        for(int j=c-1; j>=0; j--)
        {
            if(board[r][j]=='B')
                break;
            if(board[r][j]=='p')
            {
                ans++;
                break;
            }
        }
        for(int j=c+1; j<n; j++)
        {
            if(board[r][j]=='B')
                break;
            if(board[r][j]=='p')
            {
                ans++;
                break;
            }
        }
        return ans;
    }
};