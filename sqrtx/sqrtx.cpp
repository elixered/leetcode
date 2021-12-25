class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        for(long i=1; i<=x/2; i++)
        {
            if(i*i==x)
                return i;
            else if(i*i<x && (i+1)*(i+1)>x)
                return i;
        }
        return x;
    }
};