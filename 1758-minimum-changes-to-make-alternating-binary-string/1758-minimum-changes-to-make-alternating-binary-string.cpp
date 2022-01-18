class Solution {
public:
    int solve(string s)
    {
        int n = s.size();
        char prev = s[0];
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            if(s[i]==prev)
            {
                ans++;
                prev = (prev=='1'?'0':'1');
            }
            else prev = s[i];
        }
        return ans;
    }
    int minOperations(string s) {
       
       
        return min(solve(s),(int)s.size()-solve(s));
    }
};