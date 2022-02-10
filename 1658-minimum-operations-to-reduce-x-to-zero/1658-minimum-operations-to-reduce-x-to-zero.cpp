class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> map;
        int n = nums.size();
        int sum = 0;
        int ans = n+1;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            map[sum] = i;
            if(sum==x)
                ans = min(ans,i+1);
        }
        sum = 0;
        map[0] = -1;
        for(int i=n-1; i>=0; i--)
        {
            sum += nums[i];
            if(map.find(x-sum)!=map.end())
                ans = min(ans,(map[x-sum]+1+n-i));
        }
        return ans==n+1?-1:ans;
    }
};