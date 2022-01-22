class Solution {
public:
    
    vector<vector<int>> memo;
    
    bool g(int n, int pl)
    {
        if(n==0)
            return pl==0?false:true;
        if(memo[n][pl]!=-1) return memo[n][pl];
        int np = (pl==0 ? 1:0);
        if(pl==0)
        {
            for(int i=1; i*i<=n; i++)
            {
                if(g(n-i*i,np)==true)
                    return memo[n][pl] = true;
            }
            return memo[n][pl] = false;
        }
        if(pl==1)
        {
            for(int i=1; i*i<=n; i++)
            {
                if(g(n-i*i,np)==false)
                    return memo[n][pl] = false;
            }
            return memo[n][pl] = true;
        }
        return memo[n][pl] = false;
    }
    
    bool winnerSquareGame(int n) {
        memo = vector<vector<int>>(n+1,vector<int>(2,-1));
        return g(n,0);
    }
};