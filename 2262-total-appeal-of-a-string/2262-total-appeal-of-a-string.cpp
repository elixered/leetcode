class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        int n = s.size();
        vector<int> last(26,0);
        for(int i=0; i<n; i++)
        {
            last[s[i]-'a'] = i+1;
            for(auto j:last)
                ans += j;
        }
        return ans;
    }
};