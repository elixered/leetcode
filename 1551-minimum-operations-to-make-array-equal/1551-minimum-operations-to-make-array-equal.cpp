class Solution {
public:
    int minOperations(int n) {
        if(n==1) return 0;
        if(n%2==0)
            return (n/2)*(n/2);
        else return (n/2)*(n/2+1);
    }
};