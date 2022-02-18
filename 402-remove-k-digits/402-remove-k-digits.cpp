class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char c:num)
        {
            while(ans.size() && k && c<ans.back())
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while (ans.length() && k--) { ans.pop_back(); }  
        int idx = 0;
        while(idx<ans.size() && ans[idx]=='0')
            idx++;
        return idx==ans.size()?"0":string(ans.begin()+idx,ans.end());
    }
};