class Solution {
public:
    
    bool next(vector<int>& hm, int idx, string& ans)
    {
        bool f  = false;
        for(int i=idx; i>=0; i--)
        {
            if(hm[i]>0)
            {
                ans.push_back('a'+i);
                hm[i]--;
                return true;
            }
        }
        return false;
    }
    string repeatLimitedString(string s, int k) {
        int n = s.size();
        vector<int> hm(26,0);
        for(auto& c:s)
            hm[c-'a']++;
        string ans = "";
        for(int i=25; i>=0; i--)
        {
            if(hm[i]==0) continue;
            else if(hm[i]<=k)
            {
                string t(hm[i],(char)('a'+i));
                ans += t;
            }
            else
            {
                string t(k,(char)('a'+i));
                ans += t;
                hm[i] -= k;
                if(next(hm,i-1,ans)==false)
                    break;
                else i++;
            }
        }
        return ans;
    }
};