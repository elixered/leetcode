class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
    for(int i=0; i<32; i++)
    {
        int c = 0;
        for(auto n:nums)
        {
            if((n&(1<<i))!=0)
            c++;
        }
        if(c%3==1)
        {
            ans = (ans|(1<<i));
        }
    }
    return ans;
    }
};