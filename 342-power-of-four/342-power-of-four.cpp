class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n%3==1) && (n&(n-1))==0;
    }
};