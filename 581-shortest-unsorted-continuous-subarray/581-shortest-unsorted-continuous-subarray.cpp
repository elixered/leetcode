class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int l = n, r = 0;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                l = min(l,st.top());
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                r = max(r,st.top());
                st.pop();
            }
            st.push(i);
        }
        return r-l>0?r-l+1:0;
    }
};