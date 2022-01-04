class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        if(n==1)
            return v;
        for(int i=2; i<=n; i++)
        {
            int p = pow(2,i-1);
            vector<int> v2 = v;
            reverse(v2.begin(),v2.end());
            for(auto it:v2)
            {
                it = it+p;
                v.push_back(it);
            }
        }
        return v;
    }
};