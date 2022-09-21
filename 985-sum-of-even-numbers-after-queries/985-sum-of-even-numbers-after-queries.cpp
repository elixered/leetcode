class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        for(auto n:nums)
            if(n%2 == 0)
                s += n;
        vector<int> ans;
        for(auto q:queries){
            int val = q[0];
            int idx = q[1];
            if(nums[idx]%2 == 0)
                s -= nums[idx];
            nums[idx] += val;
            if(nums[idx]%2 == 0)
                s += nums[idx];
            ans.push_back(s);
        }
        return ans;
    }
};