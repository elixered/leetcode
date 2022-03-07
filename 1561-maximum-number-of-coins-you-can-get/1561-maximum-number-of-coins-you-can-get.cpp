class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end(),greater<int>());
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(i<j)
        {
            ans += piles[i+1];
            i += 2;
            j -= 1;
        }
        return ans;
    }
};