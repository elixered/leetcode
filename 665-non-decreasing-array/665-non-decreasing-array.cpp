class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return true;
        bool modified = false;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                if(modified) return false;
                modified = true;
               if(i==1 or nums[i-2]<=nums[i])
                   nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return true;
    }
};