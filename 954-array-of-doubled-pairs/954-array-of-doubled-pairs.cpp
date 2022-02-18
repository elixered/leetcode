class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        unordered_map<int,int> map;
        for(auto& it:nums)
            map[it]++;
        for(auto& it:nums)
        {
            if(map[it]==0) continue;
            map[it]--;
            int y = 2*it;
            if(map[y]<=0) return false;
            map[y]--;
        }
        return true;
    }
};