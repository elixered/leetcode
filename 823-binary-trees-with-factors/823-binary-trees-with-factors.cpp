class Solution {
public:
    
    int mod = 1e9 + 7;
    unordered_map<int,long long> mp;
    
    long long solve(unordered_set<int>& st, int curr){
        long long res = 1;
        if(mp.count(curr)) return mp[curr];
        for(auto i:st){
            if(st.count(i) && curr%i == 0 && st.count(curr/i)){
                long long ans = solve(st,i) * solve(st,curr/i);
                ans %= mod;
                res += ans;
                res %= mod;
            }
        }
        return mp[curr] = res;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_set<int> st(begin(arr),end(arr));
        int ans = 0;
        for(auto it:st){
            ans += solve(st,it);
            ans %= mod;
        }
        return ans;;
    }
};