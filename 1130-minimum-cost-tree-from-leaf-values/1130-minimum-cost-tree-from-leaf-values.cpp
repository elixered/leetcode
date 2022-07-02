class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        stack<int> st;
        st.push(INT_MAX);
        for(auto it:arr){
            while(st.top() <= it){
                int mid = st.top();
                st.pop();
                ans += mid*(min(it,st.top()));
            }
            st.push(it);
        }
        while(st.size() > 2){
            auto f = st.top();
            st.pop();
            ans += f*st.top();
        }
        return ans;
    }
};