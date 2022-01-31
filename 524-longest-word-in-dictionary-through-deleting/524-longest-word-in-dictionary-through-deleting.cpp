class Solution {
public:
    
    bool matched(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        return j>=n;
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto it:dictionary)
        {
            if(matched(s,it))
            {
                if(it.size()>ans.size())
                    ans = it;
                else if(it.size()==ans.size())
                    ans = min(ans,it);
            }
        }
        return ans;
    }
};