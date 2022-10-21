class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';
        long long curr = pow(2,n)-1;
        if(k == curr/2+1){
            return '1';
        }
        else if(k-1 < curr/2){
            return findKthBit(n-1,k);
        }
        else{
            return '1' - (findKthBit(n-1,curr-k+1)) + '0';
        }
    }
};