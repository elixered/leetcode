class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1; i<=n; i++)
        {
            ans.push_back(ans[i&(i-1)]+1);
        }
        return ans;
    }
};