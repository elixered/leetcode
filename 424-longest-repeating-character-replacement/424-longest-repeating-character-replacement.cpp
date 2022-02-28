class Solution {
public:
    int solve(string s, int k, char ch)
    {
        int diff = 0;
        int n = s.size();
        int i=0,j=0;
        int ans = 0;
        while(j<n)
        {
            if(s[j]==ch)
            {
                ans = max(ans,j-i+1);
                j++;
                continue;
            }
            else
            if(diff<k)
            {
                diff++;
                ans = max(ans,j-i+1);
            }
            else
            {
                while(i<=j && s[i]==ch)
                    i++;
                i++;
                ans = max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(char ch='A'; ch<='Z'; ch++)
        {
            ans = max(ans,solve(s,k,ch));
        }
        return ans;
    }
};