class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto it:nums)
            map[it]++;
        int count = 0;
        for(auto it:map)
        {
            if(k==0)
                count += it.second>1;
            else
                count += map.find(it.first+k)!=map.end();
        }
        return count;
    }
};