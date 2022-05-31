class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int curr = 0;
        int count = 0;
        int currend = -1;
        for(int i=0; i<nums.size(); i++)
        {
            curr += nums[i];
            if(mp.find(curr-target)!=mp.end())
            {
                if(mp[curr-target]+1 > currend)
                {
                    count++;
                    currend = i;
                }
            }
            mp[curr] = i;
        }
        return count;
        
    }
};