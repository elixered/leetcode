class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();
        for(int i=0, j=1; i<n && j<n; )
        {
            if(i>=j || nums[i]+k>nums[j])
                j++;
            else if(i>0 && nums[i]==nums[i-1] || nums[i]+k<nums[j])
                i++;
            else if(nums[i]+k==nums[j])
            {
                count++;
                i++;
            }
        }
        return count;
    }
};