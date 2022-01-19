class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans;
        while(getline(ss,word,' '))
        {
            if(word.size()==0) continue;
            ans = word+" "+ans;
        }
        ans.pop_back();
        return ans;
    }
};