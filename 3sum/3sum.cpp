class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++)
        {
            int target = -nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                if(nums[j]+nums[k]==target)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])
                        j++;
                    while(k>j && nums[k]==nums[k-1])
                        k--;
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]<target)
                    j++;
                else
                    k--;
            }
            while(i<n-1 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};