class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int numSubSets = 1<<n;
        for(int bitmask=0; bitmask<numSubSets; bitmask++)
        {
            vector<int> temp;
            for(int i=0; i<n; i++)
            {
                if((bitmask&(1<<i))!=0)
                    temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};