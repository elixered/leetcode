class Solution {
public:
    string interpret(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='G')
                ans += 'G';
            else if(s[i]==')')
                ans += 'o';
            else if(s[i]=='a')
            {
                ans += {"al"};
                i += 2;
            }
        }
        return ans;
    }
};