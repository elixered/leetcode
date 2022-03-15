class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        for(i; i<n; i++)
        {
            j = max(j,i-k);
            if(nums[i]==key)
            {
                while(j<=min(n-1,i+k))
                   ans.push_back(j++);
            }
        }
        return ans;
    }
};