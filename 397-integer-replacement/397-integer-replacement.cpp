class Solution {
public:
      int integerReplacement(int n) {
        if(n==INT_MAX) return 32;
        if (n <= 2) return n-1;
        if (n == 3) return 2;
        if (n % 2 == 0) return integerReplacement(n/2)+1;
        else return (n&2) == 0 ? integerReplacement(n-1)+1 : integerReplacement(n+1)+1;
    }
};