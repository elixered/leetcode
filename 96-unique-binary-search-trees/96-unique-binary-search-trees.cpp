class Solution {
public:
    unordered_map<int,int> map;
    int numTrees(int n) {
        if(n<=1) return 1;
        if(map.find(n)!=map.end()) return map[n];
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            ans += numTrees(i-1)*numTrees(n-i);
        }
        return map[n] = ans;
    }
};