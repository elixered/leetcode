class Solution {
public:
    bool canConstruct(string pat, string txt) {
        int m = pat.size();
        int n = txt.size();
        unordered_map<char,int> hash;
        for(auto c:pat)
            hash[c]++;
        int count = hash.size();
        for(int i=0; i<txt.size(); i++)
        {
            if(hash.find(txt[i])!=hash.end())
            {
                hash[txt[i]]--;
                if(hash[txt[i]]==0)
                    {               
                      hash.erase(hash.find(txt[i]));
                    }
            }
        }
        if(hash.size()==0) return true;
        return false;
    }
};