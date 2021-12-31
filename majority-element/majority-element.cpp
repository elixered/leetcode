class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(auto it:nums)
        {
            if(count==0)
            {
                ans = it;
                count++;
            }
            else if(it==ans)
                count++;
            else
                count--;
        }
        return ans;
    }
};