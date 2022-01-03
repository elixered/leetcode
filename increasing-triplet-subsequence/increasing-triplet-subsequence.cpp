class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()<3)
            return false;
        for(auto& it:nums)
        {
            if(ans.empty() || it>ans.back())
            {
                ans.push_back(it);
                if(ans.size()>=3)
                    return true;
            }
            else if(it<=ans[0])
                ans[0] = it;
            else ans.back()=it;
        }
        return ans.size()>=3;
    }
};