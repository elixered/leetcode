class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i=0,j=0;
        stack<int> st;
        while(i<n && j<n)
        {
            if(st.empty() or st.top()!=popped[j])
            {
                if(i<n)
                {
                    st.push(pushed[i]);
                    i++;
                }
                else break;
            }
            while(j<n && !st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.size()==0;
    }
};