class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        stack<pair<int,int>> st;
        st.push({nums[n-1]+1,INT_MAX});
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] == nums[i+1])
            {
                auto x = st.top(); st.pop();
                ans += x.first-nums[i];
                if(x.first+1<x.second)
                    st.push({x.first+1,x.second});
            }
            else
            {
                if(nums[i]+1<nums[i+1])
                    st.push({nums[i]+1,nums[i+1]});
            }
        }
        return ans;
    }
};