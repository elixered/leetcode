class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        stack<int> leftIdx;
        left[0] = 0;
        leftIdx.push(0);
        for(int i=1; i<n; i++)
        {
            while(!leftIdx.empty() && heights[i]<=heights[leftIdx.top()])
                leftIdx.pop();
            if(leftIdx.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = leftIdx.top();
            }
                leftIdx.push(i);
        }
        while(!leftIdx.empty())
            leftIdx.pop();
        right[n-1] = n-1;
        leftIdx.push(n-1);
        for(int i=n-2; i>=0; i--)
        {
            while(!leftIdx.empty() && heights[i]<=heights[leftIdx.top()])
                leftIdx.pop();
            if(leftIdx.empty())
            {
                right[i] = n;
            }
            else
            {
                right[i] = leftIdx.top();
            }
                leftIdx.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int r = right[i]==i?i:right[i]-1;
            int l = left[i]==i?i:left[i]+1;
            ans = max(ans,(r-l+1)*heights[i]);
        }
        return ans;
    }
};