class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int c = gcd(a,b);
        c = (a*b)/c;
        long long low = 1;
        long long high = pow(10,15);
        long long m = pow(10,9) + 7;
        int ans;
        while(low <= high){
            long long mid = (low+high)/2;
            long long k = mid/a + mid/b - mid/c;
            if(k > n)
                high = mid-1;
            else if(k<n) low = mid+1;
            else{
                ans = (int)(mid%m);
                high = mid-1;
            }
        }
        return ans;
    }
};