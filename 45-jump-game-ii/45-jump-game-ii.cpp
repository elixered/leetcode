class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int end = 0;
        int n = nums.size();
        int maxreach = 0;
        for(int i=0; end<n-1; end = maxreach)
        {
            count++;
            while(i<n && i<=end)
            {
                maxreach = max(maxreach,i+nums[i++]);
            }
            if(end==maxreach) return -1;
        }
        return end>=n-1?count:-1;
    }
};