class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {        
        int n = nums.size();
        if(n<2) return n;
        if(n==2) return 1 + (nums[0]!=nums[1]);
        int prev = 0;
        if(nums[1]-nums[0] > 0) prev = 1;
        else if(nums[1]-nums[0] < 0) prev = -1;
        int ans = 1;
        int curr = 1+(nums[0]!=nums[1]);
        int j=2,i=0;
        while(j < n){
            int diff = nums[j] - nums[j-1];
            if(diff*prev < 0)
            {
                curr++;
                prev = -prev;
            }
            else{
                ans = max(ans,curr);
                curr = 1+(nums[j]!=nums[j-1]);
                if(nums[j]==nums[j-1])
                    prev = 0;
                else
                prev = diff>0?1:-1;
            }
            j++;
        }
        ans = max(ans,curr);
        return ans;
    }
};