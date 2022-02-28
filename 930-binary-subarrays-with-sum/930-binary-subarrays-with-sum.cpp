class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        int curr = 0;
        for(auto it:nums)
        {
            curr += it;
            count += map[curr-goal];
            map[curr]++;
        }
        return count;
    }
};