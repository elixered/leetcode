class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size();
        int n = t.size();
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i]!=t[j])
                {
                    int sleft = i-1;
                    int tleft = j-1;
                    int left = 0;
                    while(sleft>=0 && tleft>=0 && s[sleft]==t[tleft])
                    {
                        sleft--;
                        tleft--;
                        left++;
                    }
                    int sright = i+1;
                    int tright = j+1;
                    int right = 0;
                    while(sright<m && tright<n && s[sright]==t[tright])
                    {
                        right++;
                        sright++;
                        tright++;
                    }
                    
                     ans += (left+1)*(right+1);
                }
            }
        }
        return ans;
    }
};