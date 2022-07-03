class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return n;
        vector<int> up(n,0),down(n,0);
        if(nums[0]-nums[1]>0)
        {
            up[0] = 1;
            down[0] = 0;
        }
        else if(nums[0]-nums[1]<0)
        {
            up[0] = 0;
            down[0] = 1;
        }
        for(int i=1; i<n; i++)
        {
            up[i] = up[i-1];
            down[i] = down[i-1];
            if(i==n-1)
            {
                up[i]++;
                down[i]++;
                break;
            }
            if(nums[i]-nums[i+1]>0)
            {
                up[i] = down[i-1]+1;
            }
            else if(nums[i]-nums[i+1]<0)
            {
                down[i] = up[i-1]+1;
            }
        }
        return max(down.back(),up.back());
    }
};