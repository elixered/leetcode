class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxidx = 0;
        for(int i=0; i<n && i<=maxidx; i++)
        {
            int jump = nums[i];
            maxidx = max(maxidx,i+jump);
        }
        return maxidx>=n-1;
    }
};