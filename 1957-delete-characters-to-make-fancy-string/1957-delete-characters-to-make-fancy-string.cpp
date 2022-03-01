class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n<3) return s;
        string ans = "";
        for(auto it:s)
        {
            if(ans.size()<2)
                ans.push_back(it);
            else
            {
                if(ans[ans.size()-1]==ans[ans.size()-2] && ans[ans.size()-1]==it)
                    continue;
                else ans.push_back(it);
            }
        }
        return ans;
    }
};