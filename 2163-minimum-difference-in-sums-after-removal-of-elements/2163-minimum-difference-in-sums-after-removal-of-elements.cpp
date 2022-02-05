class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        vector<ll> pref(n,0),suff(n,0);
        ll sum = 0;
        
        priority_queue<int> pqf;
        priority_queue<int,vector<int>,greater<int>> pqb;
        
        for(int i=0; i<k; i++)
        {
            sum += nums[i];
            pref[i] = sum;
            pqf.push(nums[i]);
        }
        
        for(int i=k; i<n-k; i++)
        {
            if(nums[i]<pqf.top())
            {
                sum -= pqf.top();
                pqf.pop();
                sum += nums[i];
                pqf.push(nums[i]);
            }
            pref[i] = sum;
        }
        sum = 0;
        for(int i=n-1; i>=n-k; i--)
        {
            sum += nums[i];
            suff[i] = sum;
            pqb.push(nums[i]);
        }
        
        for(int i=n-k-1; i>=k; i--)
        {
            if(nums[i]>pqb.top())
            {
                sum -= pqb.top();
                pqb.pop();
                sum += nums[i];
                pqb.push(nums[i]);
            }
            suff[i] = sum;
        }
        ll ans = INT64_MAX;
        for(int i=k; i<=2*k; i++)
        {
            ans = min(ans,pref[i-1]-suff[i]);
        }
        return ans;
    }
};