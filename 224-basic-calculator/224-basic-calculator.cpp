class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;
        int n = s.size();
        int i = 0;
        int sum = 0;
        int sign = 1;
        while(i<n){
            if(isdigit(s[i])){
                int curr = 0;
                while(i<n && isdigit(s[i])){
                    curr  = curr*10 + (s[i]-'0');
                    i++;
                }
                sum += sign*curr;
                sign = 1;
                i--;
            }
            else if(s[i] == '('){
                st.push({sum,sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i] == '-')
                sign *= -1;
            else if(s[i] == ')'){
                auto [res1,sign1] = st.top();
                st.pop();
                sum = res1+sum*sign1;
            }
            i++;
        }
        return sum;
    }
};