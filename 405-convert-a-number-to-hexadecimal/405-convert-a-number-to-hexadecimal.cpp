class Solution {
public:
    string toHex(int num) {
        unsigned int x = num;
        string s;
        string hex = "0123456789abcdef";
        do{
            int r = x%16;
            s += hex[r];
            x /= 16;
        }while(x>0);
        return string(s.rbegin(),s.rend());
    }
};