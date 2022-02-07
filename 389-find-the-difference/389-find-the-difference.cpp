class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;
        for(auto& it:t)
            x ^= (it-'a');
        for(auto& it:s)
            x ^= (it-'a');
        return ('a'+x);
    }
};