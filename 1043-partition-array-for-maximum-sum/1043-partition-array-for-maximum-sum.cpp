class Solution {
public:
    unordered_map<int,int> map;
    int solve(vector<int>& nums, int idx, int k)
    {
        if(idx>=nums.size()) return 0;
        if(map.find(idx)!=map.end()) return map[idx];
        int ans = 0;
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=idx; i<min(idx+k,n); i++)
        {
            mx = max(mx,nums[i]);
            int curr = mx*(i-idx+1);
            curr += solve(nums,i+1,k);
            ans = max(ans,curr);
        }
        return map[idx] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        return solve(nums,0,k);
    }
};