class Solution {
public:
    
    int solve(string s, int k, char ch)
    {
        int n = s.size();
        int j = 0, i = 0;
        int ans = 0;
        while(j<n)
        {
            if(s[j]==ch)
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                if(k>0)
                {
                    k--;
                    ans = max(ans,j-i+1);
                    j++;
                }
                else
                {
                    while(i<=j && s[i]==ch)
                        i++;
                    i++;
                    ans = max(ans,j-i+1);
                    j++;
                }
            }
        }
        return ans;
    }
    
    int maxConsecutiveAnswers(string s, int k) {
        return max(solve(s,k,'T'),solve(s,k,'F'));
    }
};