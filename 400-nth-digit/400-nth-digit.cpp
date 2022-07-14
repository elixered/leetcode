class Solution {
public:
    int findNthDigit(int n) {
        vector<long> digits = {0};
        for(int i=1; i<=9; ++i){
            long curr = pow(10,i) - pow(10,i-1);
            digits.push_back(curr*i);
            digits[i] += digits[i-1];
            if(digits[i] > INT_MAX)
                break;
        }
        auto itr = upper_bound(begin(digits),end(digits),n);
        itr--;
        int dig = itr - begin(digits);
        int req = (n - *itr);
        int move = req/(dig+1);
        int prev = pow(10,dig) + move - 1;
        if((req)%(dig+1) == 0)
            return prev%10;
        int id = (req)%(dig+1)-1;
        string s = to_string(prev+1);
        return s[id] - '0';
    }
};