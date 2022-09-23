class Solution {
public:
    int concatenatedBinary(int n) {
        int ans = 1;
        int m = 1e9+7;
        for(int i=2; i<=n; ++i){
            string s;
            int x = i;
            while(x){
                x /= 2;
                ans = (ans*2)%m;
            }
            ans += i;
        }
        return ans;
    }
};