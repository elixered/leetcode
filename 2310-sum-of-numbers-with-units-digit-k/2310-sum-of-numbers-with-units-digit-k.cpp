class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        for(int i=1; i<=10; i++){
            if(i*k<=num && (num-i*k)%10==0)
                return i;
        }
        return -1;
    }
};