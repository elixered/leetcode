class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        unordered_set<int> st;
        int n = nums.size();
        int m = *max_element(begin(nums),end(nums));
        unordered_map<int,int> dp;
        for(auto i:nums)
            dp[i] = 1;
        for(int i=n-1; i>=0; i--){
            int curr = nums[i];
            if(st.find(curr+d) != st.end()){
                dp[curr] = max(dp[curr], 1 + dp[*st.find(curr+d)]);
            }
            st.insert(curr);
        }
        int ans = 0;
        for(auto it:dp)
            ans = max(ans,it.second);
        return ans;
    }
};