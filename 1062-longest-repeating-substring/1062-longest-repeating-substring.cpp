class Solution {
public:
    int longestRepeatingSubstring(string S, int m_val = 0) {
	vector<vector<short>> dp(S.size() + 1, vector<short>(S.size() + 1));
	for (int i = 0; i < S.size(); ++i)
		for (int j = 0; j < i; ++j) {
			if (S[i] == S[j]) {
				auto val = dp[i + 1][j + 1] = 1 + dp[i][j];
				if (val > m_val) m_val = val;
			}
		}
	return m_val;
}
};