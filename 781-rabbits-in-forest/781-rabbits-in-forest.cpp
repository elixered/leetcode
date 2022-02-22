class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_map<int,int> map;
        for(auto it:nums)
            map[it]++;
        int ans = 0;
        for(auto it:map)
        {
            int num = it.first;
            int count = it.second;
            if(num+1==count)
                continue;
            else
            if(count<num+1)
            {
                ans += num+1-count;
            }
            else
            {
                int req = num+1;
                int groups = count/req;
                int rest = count%req;
                if(rest!=0) ans += num+1-rest;
            }
        }
        return ans+n;
    }
};