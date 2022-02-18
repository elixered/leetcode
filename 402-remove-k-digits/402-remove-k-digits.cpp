class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k>=n) return "0";
        string s(num.begin(),num.begin()+n-k);
        string ans = s;
        int sz = n-k;
        for(int i=n-k; i<n; i++)
        {
            int idx = 0;
            while(idx<s.size()-1 && s[idx]<=s[idx+1])
                idx++;
            if(idx==s.size()-1)
            {
                s[sz-1] = min(s[sz-1],num[i]);
            }
            else
            {
                s.erase(idx,1);
                s.push_back(num[i]);
            }
        }
        int idx = 0;
        while(idx<sz && s[idx]=='0')
            idx++;
        if(idx==sz) return "0";
        else return string(s.begin()+idx,s.end());
    }
};