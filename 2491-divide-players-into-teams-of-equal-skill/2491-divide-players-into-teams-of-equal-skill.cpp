class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int i=0,j=nums.size()-1;
        long long ans = 0;
        while(i<j){
            if(nums[i] + nums[j] != nums[0] + nums.back())
                return -1;
            else
                ans += nums[i]*nums[j];
            i++;
            j--;
        }
        return ans;
    }
};