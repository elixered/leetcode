class Solution {
public:
    
    int atMost(vector<int>& nums, int k)
    {
        int n = nums.size();
        int i=0,j=0;
        unordered_map<int,int> map;
        int ans = 0;
        while(j<n)
        {
            if(map.find(nums[j])==map.end())
                k--;
            map[nums[j]]++;
            while(k<0 && i<=j)
            {
                map[nums[i]]--;
                if(map[nums[i]]==0)
                {
                    k++;
                    map.erase(map.find(nums[i]));
                }
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};