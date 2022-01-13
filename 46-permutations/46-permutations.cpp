class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int start)
    {
        if(start==nums.size())
            ans.push_back(nums);
        for(int i=start; i<nums.size(); i++)
        {
            swap(nums[i],nums[start]);
            solve(nums,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};