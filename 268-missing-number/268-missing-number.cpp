class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total=0,sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            total += i+1;
        }
        return total-sum;
    }
};