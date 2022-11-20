class Solution {
public:
    
    int solve(string& s, int& i){
        int n = s.size();
        int res = 0;
        int num = 0;
        int sign = 1;
        while(i < n){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }
            else if(s[i] == '('){
                i++;
                num = solve(s,i);
            }
            else if(s[i] == ')'){
                res = res + num*sign;
                num = 0;
                return res;
            }
            else if(s[i] == '+' or s[i] == '-'){
                res += num*sign;
                num = 0;
                sign = s[i]=='+'?1:-1;
            }
            i++;
        }
        return res + sign*num;
    }
    
    int calculate(string s) {
        int i = 0;
        return solve(s,i);
    }
};