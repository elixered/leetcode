class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        map[0] = -1;
        int ans = 0;
        int s = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
                s++;
            else
                s--;
            if(map.find(s)==map.end())
                map[s] = i;
            else ans = max(ans,i-map[s]);
        }
        return ans;
    }
};