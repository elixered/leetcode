

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
        long long sum = n * (n+1) / 2;
        if (sum == target) return n;
        long long res = sum - target;
        if ((res&1) == 0) 
            return n;
        else 
            return n+((n&1) ? 2 : 1);
        
    }
};