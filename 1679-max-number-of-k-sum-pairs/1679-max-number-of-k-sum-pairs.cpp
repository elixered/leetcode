class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int ans = 0;
        while(i<j)
        {
            int curr = nums[i]+nums[j];
            if(curr>k)
                j--;
            else if(curr<k)
                i++;
            else
            {
                i++;
                j--;
                ans++;
            }
        }
        return ans;
    }
};