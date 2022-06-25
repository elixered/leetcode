class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(auto s:tokens){
            int i = -1;
            if(s=="-") i=1;
            else if(s=="*") i=2;
            else if(s=="/") i=3;
            else if(s=="+") i=0;
            if(i==-1)
                st.push(stoi(s));
            else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(i==0) a = a+b;
                else if(i==1) a = a-b;
                else if(i==2) a = a*b;
                else a = a/b;
                st.push(a);
            }
        }
        return st.top();
    }
};