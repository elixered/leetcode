class Solution {
public:
    
    int counts(vector<int>& v, int n, int start)
    {
        if(start>n) return 1;
        int ans = 0;
        for(int i=start; i<=n; i++)
        {
            if((v[i]%start==0 or start%v[i]==0))
            {
                swap(v[start],v[i]);
                ans += counts(v,n,start+1);
                swap(v[start],v[i]);
            }
        }
        return ans;
    }
    
    int countArrangement(int n) {
        vector<int> v;
        v.push_back(0);
        for(int i=0; i<n; i++)
            v.push_back(i+1);
        return counts(v,n,1);
    }
};