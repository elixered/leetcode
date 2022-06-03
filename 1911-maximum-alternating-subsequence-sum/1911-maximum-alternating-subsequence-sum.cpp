class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0, odd = 0;
        for(auto it:nums)
        {
            long long o = odd;
            odd = max(odd,even-it);
            even = max(even,o+it);
        }
        return max(even,odd);
    }
};