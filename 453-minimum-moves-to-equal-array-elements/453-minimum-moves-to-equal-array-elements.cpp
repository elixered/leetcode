class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        long long mini = INT_MAX;
        int n = nums.size();
        for(auto it:nums)
        {
            mini = min(mini,(long long)it);
            sum+=it;
        }
        
        return sum - n*mini;
    }
};