class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            int j = i;
            while(nums[j]!=INT_MAX){
                count++;
                int curr = j;
                j = nums[j];
                nums[curr] = INT_MAX;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};