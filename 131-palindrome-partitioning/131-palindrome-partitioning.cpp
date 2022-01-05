class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    
    void solve(string& s, int idx, vector<string>& temp)
    {
        if(idx>=s.size())
        {
            ans.push_back(temp);
            return;
        }
        int n = s.size();
        for(int i=idx; i<n; i++)
        {
            if(dp[idx][i]==true)
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp = vector<vector<bool>>(n,vector<bool>(n,false));
        for(int i=0; i<n; i++)
        {
            for(int c=i,r=0; c<n; c++,r++)
            {
                if(r==c)
                    dp[r][c] = true;
                else
                    if(c==r+1)
                        dp[r][c] = (s[r]==s[c]);
                else
                {
                    dp[r][c] = (dp[r+1][c-1] && s[r]==s[c]);
                }
            }
        }
        vector<string> temp;
        solve(s,0,temp);
        return ans;
    }
};