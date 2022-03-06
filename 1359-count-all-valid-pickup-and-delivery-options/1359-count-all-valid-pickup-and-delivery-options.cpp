class Solution {
public:
    #define mod (int)(pow(10,9)+7)
    #define ll long long
    int countOrders(int n) {
        if(n<=1) return n;
        ll x = (ll)countOrders(n-1);
        ll space = 2*n-1;
        ll total = (space*(space+1)/2);
        return (x*total)%mod;
    }
};