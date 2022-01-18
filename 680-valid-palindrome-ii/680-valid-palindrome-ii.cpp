class Solution {
public:
    bool solve(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
               string s1 = s.substr(i,j-i);
                string s2 = s.substr(i+1,j-i);
                return solve(s1) or solve(s2);
            }
        }
        return true;
    }
};