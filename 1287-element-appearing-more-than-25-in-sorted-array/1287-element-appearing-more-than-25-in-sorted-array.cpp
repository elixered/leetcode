class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int j = i;
            while(j<n && nums[j]==nums[i])
                j++;
            if(j-i > n/4) return nums[i];
            i = j-1;
        }
        return -1;
    }
};