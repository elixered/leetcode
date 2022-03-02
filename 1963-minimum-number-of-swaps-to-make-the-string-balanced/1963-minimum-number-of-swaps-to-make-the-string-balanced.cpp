class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto c:s)
        {
            if(st.empty() or st.top()==']' or c=='[')
                st.push(c);
            else st.pop();
        }
        return (st.size()/2+1)/2;
    }
};