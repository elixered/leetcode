class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> hm(10,0);
        for(auto c:secret)
            hm[c-'0']++;
        int bulls=0,cows=0;
        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]==guess[i])
            {
                hm[guess[i]-'0']--;
                bulls++;
            }

        }
        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]==guess[i]) continue;
            {
                if(hm[guess[i]-'0']>0)
                {
                    cows++;
                    hm[guess[i]-'0']--;
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};