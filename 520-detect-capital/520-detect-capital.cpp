class Solution {
public:
    bool detectCapitalUse(string word) {
        stringstream ss(word);
        string s;
        while(ss>>s)
        {
            if(isupper(s[0]))
            {
                if(s.size()>1)
                {
                    if(isupper(s[1]))
                    {
                        for(auto c:s)
                        {
                            if(islower(c))
                                return false;
                        }
                    }
                    else
                    {
                        for(int i=1; i<s.size(); i++)
                            if(isupper(s[i]))
                                return false;
                    }
                }
            }
            else
            {
                for(auto c:s)
                {
                    if(isupper(c))
                        return false;
                }
            }
        }
        return true;
    }
};