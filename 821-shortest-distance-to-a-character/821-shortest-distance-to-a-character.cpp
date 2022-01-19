class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        int prev = -n;
        int next = 2*n;
        vector<int> ans(n,n);
        for(int i=0; i<n; i++)
        {
            if(s[i]==c)
                prev = i;
            ans[i] = min(ans[i],i-prev);
        }
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]==c)
                next = i;
            ans[i] = min(ans[i],next-i);
        }
        return ans;
    }
};