class Solution {
public:
    #define ll long long
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(),beans.end());
        vector<ll> prefix(n), suffix(n);
        ll res = 0;
        for(int i=0; i<n; i++)
        {
            res += beans[i];
            prefix[i] = res;
        }
        for(int i=0; i<n; i++)
        {
            suffix[i] = prefix[n-1] -prefix[i] - (ll)(n-i)*beans[i];
        }
        ll ans = pow(10,17);
        for(int i=0; i<n; i++)
        {
            ans = min(ans,prefix[i]+suffix[i]);
        }
        return ans;
    }
};