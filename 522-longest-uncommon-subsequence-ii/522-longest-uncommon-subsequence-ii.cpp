class Solution {
public:
    unordered_map<string,int> mp;
    void solve(string& s, int idx, string curr)
    {
        if(idx>=s.size())
        {
            mp[curr]++;
            return;
        }
        else
        {
            solve(s,idx+1,curr);
            curr.push_back(s[idx]);
            solve(s,idx+1,curr);
        }
    }
    int findLUSlength(vector<string>& strs) {
        for(auto s:strs)
        {
            solve(s,0,"");
        }
        int ans = -1;
        for(auto it:mp)
        {
            if(it.second==1)
                ans = max(ans,(int)it.first.size());
        }
        return ans;
    }
};