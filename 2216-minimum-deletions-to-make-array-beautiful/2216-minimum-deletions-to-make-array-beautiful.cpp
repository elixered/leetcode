class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        while(i < n){
            if((i-ans)%2 != 0){
                ++i;
            }
            else{
                while(i+1 < n && nums[i] == nums[i+1]){
                    ++ans;
                    ++i;
                }
                ++i;
            }
        }
        return ans + ((n-ans)%2!=0);
    }
};