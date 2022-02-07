class Solution {
public:
    
    bool check( int k, vector<int>& hm)
    {
        for(auto& it:hm)
        {
            if(it>0 && it<k)
                return false;
        }
        return true;
    }
    
    int longestSubstring(string s, int k) {
        int n = s.size();
        int len = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> hm(26,0);
            for(int j=i; j<n; j++)
            {
                hm[s[j]-'a']++;
                if(check(k,hm))
                    len = max(len,j-i+1);
            }
        }
        return len;
    }
};