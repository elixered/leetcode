class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; ++i){
        	sum[i + 1] = sum[i] + A[i];
        }
        if(K <= 1){
        	return (1.0 * sum[n]) / n;
        }
        if(K >= n){
        	return sum[n];
        }
        vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0.0));
        for(int i = 1; i <= n; ++i){
        	dp[i][1] = (1.0 * sum[i]) / i;
        }
        for(int k = 2; k <= K; ++k){
        	for(int i = k; i <= n; ++i){
        		for(int j = i - 1; j >= k - 1; --j){
        			dp[i][k] = max(dp[i][k], dp[j][k - 1] + 1.0 * (sum[i] - sum[j]) / (i - j));
        		}
        		
        	}
        }
        return dp[n][K];
    }
};