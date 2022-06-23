class Solution {
public:
    
    int divide(vector<int>& nums, int minimum){
        int curr = 0;
        int count = 0;
        for(auto it:nums){
            curr += it;
            if(curr >= minimum){
                count++;
                curr = 0;
            }
        }
        return count + (curr >= minimum);
    }
    
    int maximizeSweetness(vector<int>& nums, int k) {
        int low = 1;
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(divide(nums,mid) >= k+1){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};