class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        if(x%10==0)
            return false;
        long long y = 0;
        long long temp = x;
        while(x)
        {
            int rem = x%10;
            x = x/10;
            y = y*10+rem;
        }
        return temp==y;
    }
};