class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hm(26,0);
        for(auto& it:t)
            hm[it-'a']++;
        for(auto& it:s)
            hm[it-'a']--;
        for(char c='a'; c<='z'; c++)
            if(hm[c-'a']>0)
                return c;
        return 'a';
    }
};