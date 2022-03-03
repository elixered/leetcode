class Solution {
public:
    
    int gcd(int a, int b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
    
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(gcd(i,j)==1)
                {
                    string s = to_string(i)+"/"+to_string(j);
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};