class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0;
        multiset<int> before,after(nums.begin(),nums.end());
        before.insert(nums[0]);
        after.erase(after.find(nums[0]));
        for(int i=1; i<nums.size()-1; i++)
        {
            after.erase(after.find(nums[i]));
            if(after.upper_bound(nums[i])==after.begin() && before.lower_bound(nums[i])==before.end())
                ans+=2;
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
                ans++;
            before.insert(nums[i]);
        }
        return ans;
    }
};