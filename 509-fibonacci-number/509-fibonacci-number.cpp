class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int secondprev = 0;
        int firstprev = 1;
        for(int i=2;i<=n; i++)
        {
            int curr = secondprev+firstprev;
            secondprev = firstprev;
            firstprev = curr;
        }
        return firstprev;
    }
};