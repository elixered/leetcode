vector<int> prefix(string text)
{
    int n = text.size();
    vector<int> prefix(n,0);
    int border=0;
    for (int i=1;i<n;++i)
    {
        while (border>0 && text[border] != text[i]) border=prefix[border-1];
        
        if (text[border] == text[i])
        {
            prefix[i] = ++border; 
        }
        else
        {
            prefix[i] = 0;
            border = 0;
        }
    }
    
    return prefix;
}

bool kmp(string text,string pattern)
{
    string look = pattern + '$' + text;
    int n = pattern.size();
    
    vector<int> p = prefix(look);
    
    for (int i=n+1;i<p.size();++i)
    {
        if (p[i] == n) return true;
    }
    
    return false;
}


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        unordered_set<string> ans;
        for (int i=0;i<words.size();++i)
        {
            for (int j=i+1;j<words.size();++j)
            {
                string w1 = words[i];
                string w2 = words[j];
                
                if (w1.size() > w2.size()) swap(w1,w2);
                
                if (kmp(w2,w1)) ans.insert(w1);
            }
        }
        
        vector<string> res(ans.begin(),ans.end());
        return res;
        
    }
};