class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0, j = n-1;
        while(i<n-1 && nums[i]<=nums[i+1])
            i++;
        while(j>0 && nums[j]>=nums[j-1])
            j--;
        if(j<=i)
            return 0;
        int ans = min(n-i-1,j);
        for(int k=i; k>=0; k--)
        {
            int idx = lower_bound(nums.begin()+j,nums.end(),nums[k])-nums.begin();
            ans = min(ans,idx-k-1);
        }
        return ans;
    }
};