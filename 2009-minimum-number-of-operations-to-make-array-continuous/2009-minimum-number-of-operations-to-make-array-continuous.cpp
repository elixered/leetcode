class Solution {
public:
    int minOperations(vector<int>& arr) {
        sort(begin(arr),end(arr));
        vector<int> nums;
        int d = 0;
        for(auto it:arr){
            if(nums.size() == 0 or nums.back() != it)
                nums.push_back(it);
            else
                d++;
        }
        int n = nums.size();
        int ans = n+d-1;
        for(int i=0; i<n; ++i){
            int idx = lower_bound(begin(nums)+i,end(nums),nums[i]+n+d-1) - begin(nums);
            if(idx == n or nums[idx] != nums[i]+n+d-1)
                idx--;
            ans = min(ans,i + n -idx - 1 + d);
        }
        return ans;
    }
};