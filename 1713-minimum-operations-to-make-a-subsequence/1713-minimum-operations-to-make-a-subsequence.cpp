class Solution {
public:
    
    int lis(vector<int>& nums)
    {
        int n = nums.size();
        if(n<=1) return n;
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            if(nums[i]>lis.back())
                lis.push_back(nums[i]);
            else
            {
                auto idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
                    
            }
        }
        return lis.size();
    }
    
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i=0; i<target.size(); i++)
        {
            if(map.find(target[i])==map.end())
                map[target[i]] = i;
        }
        vector<int> ans;
        for(int i=0; i<arr.size(); i++)
        {
            if(map.find(arr[i])!=map.end())
                ans.push_back(map[arr[i]]);
        }
        return (int)target.size() - lis(ans);
    }
};