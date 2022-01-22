class Solution {
public:
    int memo[100001][5];
    int solve(string& s, int start, int curr)
    {
        int mod = pow(10,9)+7;
        int n = s.size();
        if(curr>2) return 0;
        if(start==n-1)
        {
            curr+=(s[start]=='S'?1:0);
            if(curr==2)
                return 1;
            else return 0;
        }
        if(memo[start][curr]!=-1) return memo[start][curr];
        int ans;
        if(curr<2)
        {
            ans = solve(s,start+1,curr+(s[start]=='S'?1:0))%mod;
        }
        else
        if(curr==2)
        {
            if(s[start]=='P')
                ans = (solve(s,start+1,curr)%mod+solve(s,start+1,0)%mod)%mod;
            else
            {
                ans = solve(s,start+1,0+s[start]=='S'?1:0);
            }
                
        }
        return memo[start][curr] = ans;
    }
    

    int numberOfWays(string s) {
        int n = s.size();
        memset(memo,-1,sizeof(memo));
  
        if(n<2) return 0;
       return solve(s,0,0);
       
    }
};