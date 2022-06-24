class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), leftMin(n), rightMin(n),stack;
        for(int i=0; i<n; i++){
            int it = nums[i];
            while(!stack.empty() && nums[stack.back()]>=it){
                stack.pop_back();
            }
            leftMin[i] = stack.empty()?-1:stack.back();
            stack.push_back(i);
        }
        stack.clear();
        for(int i=n-1; i>=0; i--){
            int it = nums[i];
            while(!stack.empty() && nums[stack.back()]>=it){
                stack.pop_back();
            }
            rightMin[i] = stack.empty()?n:stack.back();
            stack.push_back(i);
        }        
        for(int i=0; i<n; i++){
            int len = rightMin[i]-leftMin[i]-1;
            ans[len-1] = max(ans[len-1],nums[i]);
        }
        for(int i=n-1; i>0; i--){
            ans[i-1] = max(ans[i-1],ans[i]);
        }
        return ans;
    }
};