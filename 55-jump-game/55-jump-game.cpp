class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxreach = 0;
        int i = 0;
        while(i < n){
            if(i > maxreach) return false;
            maxreach = max(maxreach,i+nums[i]);
            i++;
        }
        return true;
    }
};