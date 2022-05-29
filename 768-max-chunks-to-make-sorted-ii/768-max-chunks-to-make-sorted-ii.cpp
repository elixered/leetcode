class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int,set<int>> mp;
        int ans = 0;
        vector<int> nums = arr;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++)
            mp[nums[i]].insert(i);
        int maxreach = -1;
        for(int i=0; i<n; i++)
        {
            int minidx = *mp[arr[i]].begin();
            mp[arr[i]].erase(minidx);
            maxreach = max(maxreach,minidx);
            if(maxreach==i)
                ans++;
        }
        return ans;
    }
};