class Solution {
public:
    
    bool check(vector<int>& nums, int idx, int n){
        if(n == 0)
            return true;
        if(idx == nums.size() or n < 0)
            return false;
        return check(nums,idx+1,n) or check(nums,idx+1,n-nums[idx]);
    }
    
    bool checkPowersOfThree(int n) {
       vector<int> nums;
        int curr = 1;
        while(curr <= 1e7){
            nums.push_back(curr);
            curr *= 3;
        }
        return check(nums,0,n);
    }
};