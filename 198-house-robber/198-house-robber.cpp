class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prev = 0;
        int curr = nums[0];
        for(int i=1; i<n; ++i){
            int next = max(prev+nums[i],curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};