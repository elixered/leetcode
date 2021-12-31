class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int tgt = target - nums[i]-nums[j];
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    if(nums[k]+nums[l]==tgt)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[k]==nums[k+1])
                            k++;
                        while(l>k && nums[l]==nums[l-1])
                            l--;
                        k++;
                        l--;
                    }
                    else if(nums[k]+nums[l]<tgt)
                        k++;
                    else
                        l--;
                }
                while(j<n-2 && nums[j]==nums[j+1])
                    j++;
            }
            while(i<n-1 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};