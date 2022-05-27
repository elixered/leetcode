class Solution {
public:
    int numberOfSteps(int num) {
        int c = 0;
        int ones = 0;
        for(int i=0; i<32; i++)
        {
            if((num&(1<<i))!=0)
            {
                ones++;
                c = i;
            }
        }
        return ones*2+c-ones;
    }
};