class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a>b)
            return maximumScore(b,a,c);
        if(b>c)
            return maximumScore(a,c,b);
        if(a+b<=c)
            return a+b;
        else
        {
            return (a+b-c)/2+c;
        }
        return a;
    }
};