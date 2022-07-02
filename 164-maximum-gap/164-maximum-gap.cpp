class Solution {
public:
int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int maxval = *max_element(nums.begin(), nums.end());

    int exp = 1;                                 // 1, 10, 100, 1000 ...
    int radix = 10;                              // base 10 system

    vector<int> aux(nums.size());

    while(maxval){
        vector<int> count(10,0);
        vector<int> aux(nums.size(),0);
        for(auto it:nums)
            count[(it/exp)%10]++;
        for(int i=1; i<10; ++i)
            count[i] += count[i-1];
        for(int i=nums.size()-1; i>=0; --i)
            aux[--count[(nums[i]/exp)%10]] = nums[i];
        nums = aux;
        maxval /= 10;
        exp *= 10;
    }

    int maxGap = 0;

    for (int i = 0; i < nums.size() - 1; i++)
        maxGap = max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
};