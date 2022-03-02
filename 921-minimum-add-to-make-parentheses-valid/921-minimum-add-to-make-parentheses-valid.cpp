class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(auto c:s)
        {
            if(c=='(' or st.empty() or st.top()==')')
                st.push(c);
            else st.pop();
        }
        return st.size();
    }
};