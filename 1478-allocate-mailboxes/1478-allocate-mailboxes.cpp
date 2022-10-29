class Solution {
public:
    int dp[101][101];
    
    int helper(int i, int k, vector<int>& houses){
        if(i>=houses.size()) return 0;
        if(k==0){ 
            dp[i][k] = 1e9;
            return dp[i][k];
        }

        if(dp[i][k]!=-1) return dp[i][k];
        
        int ans = 1e9;
        dp[i][k] = 0;
        int mid = 0;
        
        for(int j=i;j<houses.size();j++){
            mid = (i+j)/2;
            int c = 0;
            for(int l = i; l<=j ; l++){
                c+=abs(houses[mid]-houses[l]);
            }
            ans = min(ans, c+helper(j+1, k-1, houses));
        }
        dp[i][k] = ans;
        return dp[i][k];
    }
    
    int minDistance(vector<int>& houses, int k) {
        if(houses.size()<2) return 0;
        if(k>=houses.size()) return 0;
        memset(dp, -1, sizeof(dp));
        sort(houses.begin(), houses.end());
        return helper(0, k, houses);
    }
};