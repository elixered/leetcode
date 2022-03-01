class Solution {
public:
    
    int n,k,target;
    int dp[1<<16+2];
    
    bool solve(vector<int>& nums, int sum, int mask, int count)
    {
        if(count == k-1) return true;
        if(dp[mask]!=-1) return dp[mask];
        bool ans = false;
        for(int i=0; i<n; i++)
        {
            if((mask&(1<<i))!=0) continue;
            if(sum + nums[i] > target)
                break;
            if(sum+nums[i]==target)
            {
                mask = (mask^(1<<i));
                ans = ans or solve(nums,0,mask,count+1);
                mask = (mask^(1<<i));
            }
            else
            {
                mask = (mask^(1<<i));
                ans = ans or solve(nums,sum+nums[i],mask,count);
                mask = (mask^(1<<i));
            }
        }
        return dp[mask] = ans;
    }
    
    bool makesquare(vector<int>& nums) {
        n = nums.size();
        this->k = 4;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        else target = sum/k;
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return solve(nums,0,0,0);
    }
};