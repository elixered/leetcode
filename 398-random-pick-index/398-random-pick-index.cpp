class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            this->nums = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int n = nums.size();
        int ans = -1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=target)
                continue;
            count++;
            int pb = rand()%count;if(pb==0)
                ans = i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */