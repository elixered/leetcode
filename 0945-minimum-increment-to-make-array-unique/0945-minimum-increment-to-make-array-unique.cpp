class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> map(100001,0);
        for(auto it:nums)
            map[it]++;
        int idx = 0;
        for(int i=0; i<100001; i++)
        {
            while(map[i]>0)
            {
                map[i]--;
                nums[idx++] = i;
            }
        }
        int ans = 0;
        int need = 0;
        for(auto it:nums)
        {
            ans += max(need-it,0);
            need = max(it,need)+1;
        }
        return ans;
    }
};