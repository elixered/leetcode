class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size(), left=0, right=0, ans=0;
        deque<int> mi, mx;
        while(right<n){
            while(!mx.empty() && nums[mx.back()]<=nums[right])
                mx.pop_back();
            mx.push_back(right);
            while(!mi.empty() && nums[mi.back()]>=nums[right])
                mi.pop_back();
            mi.push_back(right);
            while(!mx.empty() && !mi.empty() && nums[mx.front()]-nums[mi.front()]>limit){
                left++;
                while(!mx.empty() && mx.front()<left)
                    mx.pop_front();
                while(!mi.empty() && mi.front()<left)
                    mi.pop_front();
            }
            ans=max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};