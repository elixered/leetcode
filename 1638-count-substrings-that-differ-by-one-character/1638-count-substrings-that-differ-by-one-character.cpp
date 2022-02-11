class Solution {
public:
    int getDiff(list<char>& m1, list<char>& m2)
    {
        int count = 0;
        string s,t;
        for(auto& it:m1)
            s += it;
        for(auto& it:m2)
            t += it;
        for(int i=0; i<s.size(); i++)
            if(s[i]!=t[i])
                count++;
        return count;
    }
    int solve(string& s, string& t)
    {
        list<char> a,b;
        for(auto& it:s)
            a.push_back(it);
        int count = 0;
        int i=0,j=0;
        int n = t.size();
        while(j<n)
        {
            b.push_back(t[j]);
            if(j-i+1<s.size())
            {
                j++;
                continue;
            }
            else
            {
                int diff = getDiff(a,b);
                if(diff==1)
                {
                    count++;
                }
                b.pop_front();
                i++;
                j++;
            }
        }
        return count;
    }
    
    int countSubstrings(string s, string t) {
        vector<string> s1;
        for(int i=0; i<s.size(); i++)
        {
            string a = "";
            for(int j=i; j<s.size(); j++)
            {
                a += s[j];
                s1.push_back(a);
            }
        }
        int count = 0;
        for(auto& it:s1)
        {
            count += solve(it,t);
        }
        return count;
    }
};