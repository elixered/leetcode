class Solution {
public:
    unordered_map<long,int> mp;
    int solve(long n){
        if(mp.count(n)) return mp[n];
        if(n==1) return 0;
        if(n<1) return 1e5;
        int ans = 1e5;
        if(n%2==0)
        ans = min(ans,solve(n/2)+1);
        else ans = min({ans,solve(n+1)+1,solve(n-1)+1});
        return mp[n] = ans;
    }
    int integerReplacement(int n) {
        return solve(n);
    }
};