class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     
        int ans = 1000001;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int base = 0; base<n-2;  base++)
        {
            int left = base+1;
            int right = n-1;
            
            while(left<right)
            {
                int sum = nums[base]+nums[left]+nums[right];
                if(abs(sum-target)<abs(ans-target))
                    ans = sum;
                if(sum<target)
                    left++;
                else if(sum>target)
                    right--;
                else return target;
            }
        }
        return ans;
        
    }
};