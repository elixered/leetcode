class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s,t;
        for(auto i:word1)
            s += i;
        for(auto i:word2)
            t += i;
        return s == t;
    }
};