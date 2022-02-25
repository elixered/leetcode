class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size()) return false;
        int n = s.size();
        unordered_map<int,int> map;
        int mini = k/26;
        int rest = k%26;
        for(int i=0; i<26; i++)
        {
            map[i] = mini;
        }
        for(int i=1; i<=rest; i++)
            map[i]++;
        for(int i=0; i<n; i++)
        {
            int diff = (t[i]-s[i]);
            if(diff==0) continue;
            if(diff<0) diff += 26;
            if(map[diff]==0)
                return false;
            else
            {
                map[diff]--;
            }
        }
        return true;
    }
};