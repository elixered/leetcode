class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        long long ans  = 0;
        vector<long long> psum(n,0);
        psum[0] = nums[0];
        for(int i=1; i<n; i++)
            psum[i] += psum[i-1]+nums[i];
        for(int i=0; i<=n; i++)
        {
            while(!st.empty() && (i==n or nums[i]<=nums[st.top()]))
            {
                int currIdx = st.top();
                st.pop();
                int currmin = nums[currIdx];
                long long currsum = psum[i-1];
                if(!st.empty())
                    currsum -= psum[st.top()];
                ans = max(ans,currsum*currmin);
            }
            st.push(i);
        }
        int m = pow(10,9)+7;
        return (int)(ans%m);
    }
};