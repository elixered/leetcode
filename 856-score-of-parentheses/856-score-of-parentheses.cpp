class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int n = s.size();
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i]==')')
            {
                st.pop();
                continue;
            }
            while(i<n && s[i]=='(')
            {
                if(st.empty())
                    st.push(1);
                else st.push(st.top()*2);
                i++;
            }
            i--;
            ans += st.top();
        }
        return ans;
    }
};