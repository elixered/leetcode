class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n = s.size();
        unordered_set<char> set;
        int ans = 0;
        while(j<n)
        {
            char ch = s[j];
            if(set.find(ch)==set.end())
            {
                set.insert(ch);
                j++;
            }
            else
            {
                ans = max(ans,j-i);
                while(i<j && s[i]!=ch)
                {
                    set.erase(s[i++]);
                }
                set.erase(s[i++]);
                set.insert(ch);
                j++;
            }
        }
        return max(ans,j-i);
    }
};