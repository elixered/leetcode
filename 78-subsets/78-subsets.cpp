class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& temp, int start)
    {
        ans.push_back(temp);
        for(int i=start; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);
            backtrack(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        backtrack(nums,temp,0);
        return ans;
    }
};