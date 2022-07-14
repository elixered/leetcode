class Solution {
public:
    string solveEquation(string s) {
        int l = 0, lx = 0, r = 0, rx = 0;
        int n = s.size();
        int i = 0;
        int sign = 1;
        while(s[i] != '='){
            if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == 'x')
                lx += sign;
            else{
                int curr = 0;
                while(i<n && isdigit(s[i])){
                    curr = curr*10 + s[i++]-'0';
                }
                if(s[i] == 'x')
                    lx += sign*curr;
                else 
                    l += sign*curr;
                if(s[i] != 'x')
                    --i;
            }
            i++;
        }
        ++i;
        sign = 1;
         while(i<n){
            if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == 'x')
                rx += sign;
            else{
                int curr = 0;
                while(i<n && isdigit(s[i])){
                    curr = curr*10 + s[i++]-'0';
                }
                if(i<n && s[i] == 'x')
                    rx += sign*curr;
                else 
                    r += sign*curr;
                if(i<n && s[i] != 'x')
                    --i;
            }
            ++i;
        }
        if(lx == rx) return r-l == 0 ? "Infinite solutions" : "No solution";
        if(lx < rx){
            swap(lx,rx);
            swap(l,r);
        }
        int y = gcd(lx-rx,r-l);
        return ((lx-rx)/y > 1 ? to_string((lx-rx)/y) : "") + "x=" + to_string((r-l)/y);
    }
};