class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i=0;
        while(i<n)
        {
            int j=i;
            while(j<n-1 && nums[j]<nums[j+1])
                j++;
            if(j==i)
            {
                i++;
                continue;
            }
            int k = j;
            while(j<n-1 && nums[j]>nums[j+1])
                j++;
            if(j-i+1<3 or j==k)
            {
                i=j;
                continue;
            }
            ans = max(ans,j-i+1);
            i = j;
        }
        return ans;
    }
};