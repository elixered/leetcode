class Solution {
public:
    bool paired(char a, char b)
    {
        return (a=='(' && b==')' or (a=='{' && b=='}') or (a=='[' && b==']'));
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(auto c:s)
        {
            if(c=='(' or c=='[' or c=='{')
                st.push(c);
            else 
            {
                if(st.empty() or !paired(st.top(),c))
                    return false;
                else st.pop();
            }
        }
        return st.size()==0;
    }
};