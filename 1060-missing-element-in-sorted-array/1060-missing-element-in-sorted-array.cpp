class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = nums[0]+1;
        for(int i=1; i<n; i++){
            int diff = nums[i] - mini;
            if(diff < k){
                k -= diff;
                mini = nums[i]+1;
            }
            else return mini+k-1;
        }
        return mini+k-1;
    }
};