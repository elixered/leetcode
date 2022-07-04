class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n;
        vector<int> nums(n,1);
        for(int i=1; i<n; ++i){
            if(ratings[i] > ratings[i-1]){
                if(nums[i] <= nums[i-1]){
                    ans += nums[i-1]-nums[i]+1;
                    nums[i] = nums[i-1]+1;
                }
            }
        }
        for(int i=n-2; i>=0; --i){
            if(ratings[i] > ratings[i+1]){
                if(nums[i] <= nums[i+1]){
                    ans += nums[i+1]-nums[i]+1;
                    nums[i] = nums[i+1]+1;
                }
            }
        }
        return ans;
    }
};