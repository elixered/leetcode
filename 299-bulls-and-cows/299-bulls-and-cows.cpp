class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s(10,0),g(10,0);

        int bulls=0,cows=0;
        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]==guess[i] )
            {
                bulls++;
            }
            else
            {
               if(g[secret[i]-'0']>0)
               {
                   g[secret[i]-'0']--;
                   s[secret[i]-'0']--;
                   cows++;
               }
                
                if(s[guess[i]-'0']>0)
                {
                    s[guess[i]-'0']--;
                    g[guess[i]-'0']--;
                    cows++;
                }
                g[guess[i]-'0']++;
                s[secret[i]-'0']++;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};