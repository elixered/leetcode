class Solution 
{
public:
   string lastSubstring(string s) {
        string temp=s;
        sort(temp.begin(),temp.end());
        char ch=temp.back();
        int ans=s.find(ch);
        for(int i=ans+1;i<s.length();i++)
        {
            if(s[i]==ch)
            {
              int  j=1;
                while(ans+j<i&&s[i+j]==s[ans+j])
                {
                    j++;
                }
                if(s[i+j]>s[ans+j])
                {
                    ans=i;
                }
                    i=i+j-1;
            }
        }
        return s.substr(ans);
    }
};