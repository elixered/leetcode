class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans(n+1,0);
        int min = 0, max=n;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='I')
                ans[i] = min++;
            else
                ans[i] = max--;
        }
        ans[n] = max;
        return ans;
    }
};