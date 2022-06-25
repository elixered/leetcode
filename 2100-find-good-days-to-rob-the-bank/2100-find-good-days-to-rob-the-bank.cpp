class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        vector<int> ans;
        int n = nums.size();
        vector<int> increasing(n,1), decreasing(n,1);
        for(int i=1; i<n; i++){
            if(nums[i] <= nums[i-1])
                decreasing[i]+=decreasing[i-1];
        }
        for(int i=n-2; i>=0; i--){
            if(nums[i] <= nums[i+1])
                increasing[i]+=increasing[i+1];
        }
        for(int i = time; i + time < n; i++){
            if(increasing[i] >= time+1 && decreasing[i]>=time+1)
                ans.push_back(i);
        }
        return ans;
    }
};