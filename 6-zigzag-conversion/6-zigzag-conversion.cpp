class Solution {
public:
    string convert(string s, int r) {
        string ans;
        int n = s.size();
        vector<string> grid(n);
        int i = 0;
        while(i<n)
        {
            int j = 0;
            while(j<r)
            {
                if(i>=n) break;
                grid[j++].push_back(s[i++]);
            }
            j = r-2;
            while(j>0)
            {
                if(i>=n) break;
                grid[j--].push_back(s[i++]);
            }
        }
        for(auto it:grid)
            ans += it;
        return ans;
    }
};