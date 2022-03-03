class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n<3) return 0;
        for(int i=0; i<n-2; i++)
        {
            int diff = nums[i+1]-nums[i];
            int j = i+2;
            while(j<n && nums[j]-nums[j-1]==diff)
                j++;
            j--;
            int k = j-i+1;
            i = j-1;
            if(k>=3)
                ans += k*(k+1)/2 - k - (k-1);
        }
        return ans;
    }
};