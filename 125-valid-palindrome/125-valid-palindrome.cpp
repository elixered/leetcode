class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string t = s;
        int i=0,j=t.size()-1;
        while(i<j)
        {
            if(!isalnum(t[i]))
                i++;
            else if(!isalnum(t[j]))
                j--;
            else
            if(t[i++]!=t[j--])
                return false;
        }
        return true;
    }
};