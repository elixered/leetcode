class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long long high = sqrt(c)+1;
        while(low<=high)
        {
            long long val = low*low + high*high;
            if(val==c)
                return true;
            else if(val>c)
                high--;
            else
                low++;
        }
        return false;
    }
};