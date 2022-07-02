class Solution {
public:
    vector<int> v1,v2;
    int mx = pow(10,5);
    int dp[20003][2];
    
    int solve(vector<int>& arr, int idx, int jump){
        if(idx==arr.size()-1) return 1;
        if(dp[idx][jump%2] != -1) return dp[idx][jump%2];
        int ans = 0;
        if(jump%2 != 0){
            int nextIdx = v1[idx];
            if(nextIdx != -1)
                ans += solve(arr,nextIdx,jump+1);
        }
        else{
            int nextIdx = v2[idx];
            if(nextIdx != -1)
                ans += solve(arr,nextIdx,jump+1);
        }
        return dp[idx][jump%2] = ans;
    }
    
    int oddEvenJumps(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        v1.resize(n,0);
        v2.resize(n,0);
        map<int,int> s1,s2;
        s1.insert({nums[n-1],n-1});
        s2.insert({nums[n-1],n-1});
        v1[n-1] = -1;
        for(int i=n-2; i>=0; i--){
            auto itr = s1.lower_bound(nums[i]);
            if(itr == s1.end())
                v1[i] = -1;
            else v1[i] = itr->second;
            auto itr2 = s2.lower_bound(nums[i]);
            if(itr2 == s2.begin() && itr2->first!=nums[i])
                v2[i] = -1;
            else{
                if(itr2->first != nums[i])
                    itr2--;
                v2[i] = itr2->second;
            }
            s1[nums[i]] = i;
            s2[nums[i]] = i;
        }
        int ans = 0;
        for(int i=0; i<n; ++i)
            ans += solve(nums,i,1);
        return ans;
    }
};