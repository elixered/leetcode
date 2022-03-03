class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1),right(n,1);
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            if(v.empty() or v.back()<nums[i])
            {
                v.push_back(nums[i]);
                left[i] = v.size();
            }
            else
            {
                auto it = lower_bound(v.begin(),v.end(),nums[i]);
                *it = nums[i];
                left[i] = it-v.begin()+1;
            }
        }
        v.clear();
        for(int i=n-1; i>=0; i--)
        {
            if(v.empty() or v.back()<nums[i])
            {
                v.push_back(nums[i]);
                right[i] = v.size();
            }
            else
            {
                auto it = lower_bound(v.begin(),v.end(),nums[i]);
                *it = nums[i];
                right[i] = it-v.begin()+1;
            }
        }
  
        int ans = n;
        for(int i=1; i<n-1; i++)
        {
            if(left[i]==1 or right[i]==1) continue;
            ans = min(ans,n-left[i]-right[i]+1);
        }
        return ans;
    }
};