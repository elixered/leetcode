class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int a = nums[i];
                int b = nums[j];
                int c = a+b;
                auto idx = lower_bound(nums.begin()+j+1,nums.end(),c)-nums.begin();
                if(idx==n) idx--;
                else if(nums[idx]>=c) idx--;
                cnt += idx-j;
            }
        }
        return cnt;
    }
};