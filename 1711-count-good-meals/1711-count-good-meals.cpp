class Solution {
public:
    int countPairs(vector<int>& nums) {
        int p = 1;
        int ans = 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,long> ump;
        for(auto it:nums)
            ump[it]++;
        int m = pow(10,9)+7;
        for(int k=1; k<=29; k++)
        {
            if(k>1) p *= 2;
            int i=0, j = nums.size()-1;
            while(i<j)
            {
                int s = nums[i]+nums[j];
                if(s>p)
                    j-=ump[nums[j]];
                else if(s<p)
                    i+=ump[nums[i]];
                else
                {
                    if(nums[i]==nums[j])
                        ans += (ump[nums[i]]*(ump[nums[i]]-1)/2)%m;
                    else ans += ump[nums[i]]*ump[nums[j]];
                    i += ump[nums[i]];
                    j -= ump[nums[j]];
                    ans %= m;
                }
            }    
        }
        return ans;
    }
};