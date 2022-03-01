class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto it:nums)
            set.insert(it);
        int ans = 0;
        for(auto it:nums)
        {
            int curr = it;
            int count = 0;
            while(set.find(curr)!=set.end())
            {
                count++;
                set.erase(set.find(curr));
                curr--;
            }
            curr = it+1;
            while(set.find(curr)!=set.end())
            {
                count++;
                set.erase(set.find(curr));
                curr++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};