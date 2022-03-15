class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<char> st;
        for(auto c:s)
        {
            if(c==')')
            {
                if(st.empty())
                    continue;
                else 
                {
                    st.pop();
                    ans += c;
                }
            }
            else
            {
                ans += c;
                if(c=='(')
                    st.push(c);
            }
        }
        string res;
        stack<char> st1;
        for(int i=ans.size()-1; i>=0; i--)
        {
            char c = ans[i];
            if(c=='(')
            {
                if(st1.empty())
                    continue;
                else 
                {
                    st1.pop();
                    res.push_back(c);
                }
            }
            else
            {
                res.push_back(c);
                if(c==')')
                    st1.push(c);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};