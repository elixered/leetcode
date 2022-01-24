class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        for(int i=m-1; i>=0; i--)
        {
            int prev = n-1;
            for(int j=n-1; j>=0; j--)
            {
                if(box[i][j]=='.')
                {
                    if(box[i][prev]!='.')
                    prev = j;
                }
                else if(box[i][j]=='*')
                {
                    prev = j-1;
                }
                else
                {
                    box[i][prev] = '#';
                    if(prev!=j)
                    box[i][j] = '.';
                    prev--;
                }
            }
        }
        vector<vector<char>> ans(n,vector<char>(m));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans[j][m-i-1] = box[i][j];
            }
        }
        return ans;
    }
};