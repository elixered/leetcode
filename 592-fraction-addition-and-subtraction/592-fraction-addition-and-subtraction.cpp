class Solution {
public:
    
    pair<int,int> getFraction(string& s, int& i, int sign){
        int num,deno=0;
        int n = s.size();
            int curr = 0;
            while(isdigit(s[i]))
                curr = curr*10 + s[i++] - '0';
            num = sign*curr;
            ++i;
            curr = 0;
            while(i<n && isdigit(s[i]))
                curr = curr*10 + s[i++] - '0';
            deno = curr == 0? 1 : curr;
        return {num,deno};
    }
    
    void add(int& num1, int& deno1, int num2, int deno2,int sign){
        num1 = deno2*num1 + deno1*num2;
        deno1 = deno1*deno2;
        int x = gcd(num1,deno1);
        num1 /= x;
        deno1 /= x;
    }
    
    string fractionAddition(string s) {
        int num1 = 0, deno1 = 0;
        int n = s.size();
        int i = 0;
        int sign = 1;
        while(i<n){
            if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else{
                pair<int,int> num = getFraction(s,i,sign);
                if(i< n){ sign = s[i] == '+' ? 1 : -1;}
                if(deno1 == 0){
                    num1 = num.first;
                    deno1 = num.second;
                }
                else add(num1,deno1,num.first,num.second,sign);
            }
            ++i;
        }
        return to_string(num1) + "/"+to_string(deno1);
    }
};