class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> p(n);
        p[0] = arr[0];
        for(int i=1; i<n; i++)
            p[i] = p[i-1]^arr[i];
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j; k<n; k++)
                {
                    int prev = i>0?p[i-1]:0;
                    if((prev^p[j-1]) == (p[j-1]^p[k]))
                        ans++;
                }
            }
        }
        return ans;
    }
};