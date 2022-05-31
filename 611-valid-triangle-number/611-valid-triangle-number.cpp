class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0) continue;
            int k = i+2;
            for(int j=i+1; j<n; j++)
            {
                while(k<n && nums[i]+nums[j]>nums[k])
                    k++;
                cnt += k-j-1;
            }
        }
        return cnt;
    }
};