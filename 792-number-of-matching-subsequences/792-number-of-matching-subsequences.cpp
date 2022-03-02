class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        for(auto word : words){
           bool flag = true;
            int prev = -1;
            for(auto c:word)
            {
                auto pos = upper_bound(mp[c].begin(),mp[c].end(),prev);
                if(pos==mp[c].end())
                {
                    flag = false;
                    break;
                }
                else prev = *pos;
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};