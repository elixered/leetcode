class Solution {
public:
    
    bool prime(int x)
    {
        if(x<=2) return true;
        for(int i=2; i*i<=x; i++)
            if(x%i==0) return false;
        return true;
    }
    
    bool isThree(int n) {
        if(n<=3) return false;
        int x = sqrt(n);
        if(x*x==n && prime(x))
            return true;
        return false;
    }
};