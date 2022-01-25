class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int j=i;
            while(j<n-1 && nums[j]==nums[j+1])
                j++;
            if(j-i+1>=2)
            {
                nums[idx++] = nums[i];
                nums[idx++] = nums[i];
            }
            else nums[idx++] = nums[i];
            i = j;
        }
        return idx;
    }
};