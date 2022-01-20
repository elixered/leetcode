class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(i==j)
                return 1;
            if(s[i]!=s[j])
                return j-i+1;
            char ch = s[i];
            while(i<j && s[i]==ch)
                i++;
            if(i==j) return 0;
            while(j>=i && s[j]==ch)
                j--;
        }
        return 0;
    }
};