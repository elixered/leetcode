class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        int j = ceil(n/2.0)-1;
        for(int i=0; i<n; i+=2)
            ans[i] = nums[j--];
        j = n-1;
        for(int i=1; i<n; i+=2)
            ans[i] = nums[j--];
        nums = ans;
    }
};