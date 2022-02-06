class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        for(int i=1; i<n; i++)
            nums[i] += nums[i-1];
        for(int i=0; i<n; i++)
        {
            int left = i>0?nums[i-1]:0;
            int right = i<n-1?nums[n-1]-nums[i]:0;
            if(left==right) return i;
        }
        return -1;
    }
};