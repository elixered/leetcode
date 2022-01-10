class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> pat;
        unordered_map<string,char> match;
        stringstream ss(s);
        string word;
        int i=0;
        while(getline(ss,word,' '))
        {
            char c = pattern[i];
            if(pat.find(c)!=pat.end() && pat[c]!=word)
                return false;
            if(match.find(word)!=match.end() && match[word]!=c)
                return false;
            pat[c] = word;
            match[word] = c;
            i++;
        }
        if(pattern.size()>i)
            return false;
        return true;
    }
};