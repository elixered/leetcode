class Solution {
public:
    unordered_map<int,vector<int>> map;
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            map[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int i = rand()%map[target].size();
        return map[target][i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */