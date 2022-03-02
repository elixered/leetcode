class Solution {
public:
    
    bool check(string s, string t)
    {
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]<t[i]) return false;
        }
        return true;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(check(s1,s2)) return true;
        return check(s2,s1);
    }
};