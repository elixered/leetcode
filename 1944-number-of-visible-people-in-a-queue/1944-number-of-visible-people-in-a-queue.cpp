class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            int count = 0;
            while(!st.empty() && heights[i]>=st.top()){
                count++;
                st.pop();
            }
            if(!st.empty())
                ans[i] = count+1;
            else ans[i] = count;
            st.push(heights[i]);
        }
        return ans;
    }
};