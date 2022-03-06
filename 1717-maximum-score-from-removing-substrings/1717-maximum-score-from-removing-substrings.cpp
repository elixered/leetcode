class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<int> st;
        int ans = 0;
        
        if(x>y)
        {
            for(auto c:s)
            {
                if(st.empty() or c!='b')
                    st.push(c);
                else
                {
                    if(st.top()=='a')
                    {
                        ans += x;
                        st.pop();
                    }
                    else st.push(c);
                }
            }
            stack<char> st2;
            while(st.size()>0)
            {
                char first = st.top();
                st.pop();
                if(st2.empty() or st2.top()!='a' or first !='b')
                    st2.push(first);
                else
                {
                    st2.pop();
                    ans += y;
                }
            }
        }
        else
        {
            for(auto c:s)
            {
                if(st.empty() or c!='a')
                    st.push(c);
                else
                {
                    if(st.top()=='b')
                    {
                        ans += y;
                        st.pop();
                    }
                    else st.push(c);
                }
            }
            stack<char> st2;
            while(st.size()>0)
            {
                char first = st.top();
                st.pop();
                if(st2.empty() or st2.top()!='b' or first !='a')
                    st2.push(first);
                else
                {
                    st2.pop();
                    ans += x;
                }
            }
        }
        return ans;
    }
};