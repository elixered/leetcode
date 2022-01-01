class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int ans = 0;
        while(getline(ss,word,' '))
        {
            if(word.size()!=0)
            {
                ans = word.size();
            }
        }
        return ans;
    }
};