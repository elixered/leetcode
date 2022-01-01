class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int n = columnTitle.size();
        for(int i=n-1; i>=0; i--)
        {
            ans += pow(26,n-1-i)*(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};