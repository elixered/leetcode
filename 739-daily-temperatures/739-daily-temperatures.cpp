class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        st.push({0,0});
        vector<int>  ans(n,0);
        for(int i=n-1; i>=0; i--)
        {
            int currTemp = nums[i];
            while(st.size()>1 && currTemp >= st.top().first)
                st.pop();
            if(st.size()>1)
                ans[i] = st.top().second-i;
            st.push({nums[i],i});
        }
        return ans;
    }
};