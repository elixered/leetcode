class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)
            return 0;
        int sign;
        if(x>=0)
            sign = 1;
        else sign = -1;
        x = abs(x);
        int n = 0;
        while(x>0)
        {
            int r = x%10;
            x /= 10;
            if(sign > 0)
            {
                if(n > (INT_MAX-r)/10)
                    return 0;
                n = n*10 + r;
            }
            else
            {
                if(n < (INT_MIN+r)/10)
                    return 0;
                n = n*10-r;
            }
        }
        return n;
    }
};