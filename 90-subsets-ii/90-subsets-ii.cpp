class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> subSets;
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
            sort(temp.begin(),temp.end());
            subSets.insert(temp);
        }
        vector<vector<int>> ans;
        for(auto it:subSets)
            ans.push_back(it);
        return ans;
    }
};