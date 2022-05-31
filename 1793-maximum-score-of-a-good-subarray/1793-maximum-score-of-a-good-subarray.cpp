class Solution {
public:
    int maximumScore(vector<int>& heights, int k) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i=0; i<=n; i++)
        {
            while(!st.empty() && (i==n || heights[i]<=heights[st.top()]))
            {
                auto idx = st.top();
                int height = heights[idx];
                st.pop();
                int l = st.empty()?-1:st.top();
                int width = i-l-1;
                int curr = width*height;
                if(i>k && l<k)
                ans = max(ans,curr);
            }
            st.push(i);
        }
        return ans;
    }
};