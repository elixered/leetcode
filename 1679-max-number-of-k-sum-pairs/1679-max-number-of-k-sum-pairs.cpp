class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int ans = 0;
        for(auto i:nums)
            ump[i]++;
        for(auto x:nums)
        {
            if(ump.find(k-x)!=ump.end())
            {
                if(ump[x]--<=0) continue;
                if(ump[k-x]--<=0) continue;
                ans++;
            }
        }
        return ans;
    }
};