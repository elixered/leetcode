class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int mod = pow(10,9)+7;
        int ans = 0;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            int t = target-nums[i];
            int j = i+1;
            int k = nums.size()-1;
            
            while(j<k)
            {
                if(nums[j]+nums[k]<t)
                    j++;
                else if(nums[j]+nums[k]>t)
                    k--;
                else if(nums[j]!=nums[k])
                {
                    int left = 1;
                    int right = 1;
                    while(j+1<k && nums[j]==nums[j+1])
                    {
                        left++;
                        j++;
                    }
                    while(k-1>j && nums[k]==nums[k-1])
                    {
                        right++;
                        k--;
                    }
                    ans = (ans+left*right)%mod;
                    j++;
                    k--;
                }
                else
                {
                    ans = (ans + (k-j+1)*(k-j)/2)%mod;
                    break;
                }
            }
        }
        return ans;
    }
};