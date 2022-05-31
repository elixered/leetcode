class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
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
                int width;
                if(st.empty()) width = i;
                else width = i-st.top()-1;
                int curr = width*height;
                ans = max(ans,curr);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> heights(n,0);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]=='0')
                    heights[j] = 0;
                else heights[j]++;
            }
            int x = largestRectangleArea(heights);
            ans = max(ans,x);
        }
        return ans;
    }
};