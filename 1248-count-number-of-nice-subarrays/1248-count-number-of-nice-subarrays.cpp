class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto& it:nums)
            it = it%2;
        int sum = 0;
        int count = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(auto it:nums)
        {
            sum += it;
            count += map[sum-k];
            map[sum]++;
        }
        return count;
    }
};