class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i=1; i<n; i++)
        {
            ans = gcd(ans,nums[i]);
            if(ans==1) return true;
        }
        return ans==1;
    }
};