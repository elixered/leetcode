class Solution {
public:
    bool solve(string s,int i, int j)
    {
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
               
                return solve(s,i,j-1) or solve(s,i+1,j);
            }
        }
        return true;
    }
};