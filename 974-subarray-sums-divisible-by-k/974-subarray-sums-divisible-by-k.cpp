class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        vector<int> prefix(n);
        int res = 0;
        for(int i=0; i<n; i++)
        {
            res += nums[i];
            prefix[i] = res;
        }
        mp[0] = 1;
        for(auto& it:prefix)
        {
            int rem = it%k;
            if(rem<0)
                rem+=k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};