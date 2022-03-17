class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int n = s.size();
        stack<int> st;
        st.push(1);
        for(int i=1; i<n; i++)
        {
            if(s[i]=='(')
            {
                if(st.empty())
                    st.push(1);
                else
                st.push(st.top()*2);
            }
            else
            {
                ans += st.top();
                st.pop();
                i++;
                while(i<n && s[i]==')')
                {
                    st.pop();
                    i++;
                }
                i--;
            }
        }
        return ans;
    }
};