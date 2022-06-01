class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for(int i=0; i<m; i++)
        {
            int j = 0;
            int c = 0;
            while(j<n)
            {
                bool flag = true;
                if(board[i][j]!='X') flag = false;
                if(i<m-1 && board[i+1][j]=='X') flag = false;
                if(i>0 && board[i-1][j]=='X') flag = false;
                if(flag == false)
                {
                    j++;
                    continue;
                }
                c++;
                while(j<n && board[i][j]=='X')
                {
                    j++;
                }
            }
            count += c;
        }
        for(int j=0; j<n; j++)
        {
            int i = 0;
            int c = 0;
            while(i<m)
            {
                bool flag = true;
                if(board[i][j]!='X') flag = false;
                if(j<n-1 && board[i][j+1]=='X') flag = false;
                if(j>0 && board[i][j-1]=='X') flag = false;
                if(flag==false)
                {
                    i++;
                    continue;
                }
                c++;
                int sz = 0;
                while(i<m && board[i][j]=='X')
                {
                    i++;
                    sz++;
                }
                if(sz==1) c--;
            }
            count += c;
        }
        return count;
    }
};