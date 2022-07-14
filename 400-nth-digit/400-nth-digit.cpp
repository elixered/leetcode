class Solution {
public:
    int findNthDigit(int n) {
        int base = 9;
        long digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits++;
        }
        
        int index = (n - 1) % digits;
        int offset = (n - 1) / digits;
        long start = pow(10, digits - 1);
        return to_string(start + offset)[index] - '0';
    }
};