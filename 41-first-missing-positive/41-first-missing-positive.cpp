class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]<=0) continue;
            int correctidx = nums[i]-1;
            while(correctidx>=0 && correctidx<n && nums[correctidx]!=nums[i])
            {
                swap(nums[i],nums[correctidx]);
                if(nums[i]<=0) break;
                correctidx = nums[i]-1;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(i+1!=nums[i])
                return i+1;
        }
        return n+1;
    }
};