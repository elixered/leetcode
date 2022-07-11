class Solution {
public:
    int maximumBeauty(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,pair<int,int>> mp;
        for(int i=0; i<n; ++i){
            if(mp.count(nums[i]))
                mp[nums[i]] = {mp[nums[i]].first,i};
            else
                mp[nums[i]] = {i,i};
        }
        vector<int> psum(n+1,0);
        for(int i=1; i<=n; ++i){
            if(nums[i-1] > 0)
                psum[i] += psum[i-1] + nums[i-1];
            else psum[i] = psum[i-1];
        }
        int ans = INT_MIN;
        for(auto it:mp){
            int sum = 2*it.first + psum[it.second.second] - psum[it.second.first+1];
            if(it.second.first != it.second.second){
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};