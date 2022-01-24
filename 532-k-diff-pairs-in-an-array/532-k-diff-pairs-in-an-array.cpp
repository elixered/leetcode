class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> arr;
        unordered_map<int,int> map;
        for(auto it:nums)
            map[it]++;
        for(int i=0; i<n; i++)
        {
            while(i<n-1 && nums[i]==nums[i+1])
                i++;
            arr.push_back(nums[i]);
        }
        int count = 0;
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=i+1; j<arr.size(); j++)
            {
                if(abs(arr[i]-arr[j])==k)
                    count++;
            }
        }
        if(k==0)
        {
            for(auto it:map)
            {
                if(it.second>1)
                    count++;
            }
        }
        return count;
    }
};