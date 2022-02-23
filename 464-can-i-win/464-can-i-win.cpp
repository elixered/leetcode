class Solution {
public:
    int memo[1<<20] = {};
    bool dfs(int m, int t, int k)
    {
        if(memo[k]!=0) return memo[k]>0;
        if(t<=0) return false;
        
        for(int i=0; i<m; i++)
        {
            if((k&(1<<i))==0 && dfs(m,t-i-1,k|(1<<i))==false)
            {
                memo[k] = 1;
                return true;
            }
        }
        memo[k] = -1;
        return false;
    }
    bool canIWin(int m, int t) {
        int sum = m*(m+1)/2;
        if(t<2) return true;
        else if(sum<t) return false;
        else if(sum==t) return m%2!=0;
        else return dfs(m,t,0);
    }
};