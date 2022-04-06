class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n = nums.size();
        long ans = 0;
        int m = pow(10,9)+7;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++)
        {
            int j=i+1;
            int k=n-1;
            int req = target-nums[i];
            while(j<k)
            {
                int s = nums[j]+nums[k];
                if(s>req)
                    k--;
                else if(s<req)
                    j++;
                else
                {
                    if(nums[j]==nums[k])
                    {
                        long c = k-j+1;
                        ans += (c*(c-1))/2;
                        j=k+1;
                    }
                    else
                    {
                        long c1 = 1, c2 = 1;
                        while(j+1<=k && nums[j]==nums[j+1])
                        {
                            c1++;
                            j++;
                        }
                        while(k-1>=j && nums[k]==nums[k-1])
                        {
                            k--;
                            c2++;
                        }
                        j++;
                        k--;
                        ans += c1*c2;
                    }
                }
                ans %= m;
            }
        }
        return ans;
    }
};