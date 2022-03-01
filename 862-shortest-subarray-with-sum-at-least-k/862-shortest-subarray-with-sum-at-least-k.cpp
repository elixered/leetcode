class Solution {
public:
    #define ll long long
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        ll sum = 0;
        deque<pair<ll,int>> dq;
        int ans = n+n;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(sum >= k)
            {
                ans = min(ans,i+1);
            }
            while(!dq.empty() && sum-dq.front().first>=k)
            {
                ans = min(ans,i-dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() && dq.back().first >= sum)
                dq.pop_back();
            dq.push_back({sum,i});
        }
        
        return ans == 2*n?-1:ans;
    }
};