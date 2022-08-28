class Solution {
public:
    int m = 1e9 + 7;
    
    long long power(long long a, long long b){
        if(b == 0)
            return 1ll;
        long long res = power(a,b/2);
        if(b%2 == 0)
            return ((res%m)*(res%m))%m;
        else
            return ((res%m)*(res%m)*(a%m))%m;
    }
    
    int countGoodNumbers(long long n) {
        auto fours = (n)/2;
        auto fives = n - fours;
        return ((power(4ll,fours)%m)*(power(5ll,fives)%m)%m);
    }
};