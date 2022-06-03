class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
                while(i<n-1 && nums[i+1]>=nums[i])
                    i++;
                ans += nums[i];
                int j = i+1;
                while(j<n && nums[j]<=nums[j-1])
                    j++;
                if(j==n) break;
                else ans -= nums[j-1];
            i = j-1;
        }
        return ans;
    }
};