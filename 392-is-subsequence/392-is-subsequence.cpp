class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m>n) return false;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        return i==m;
    }
};