class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
        double left = INT_MAX, right = INT_MIN, mid;
        for(int num:nums){
            right = max(right, double(num));
            left = min(left, double(num));
        }
        while(left + 0.00001 < right){
            mid = left + (right - left)/2;
            if(islarger(nums, mid, k))right = mid;
            else left = mid;
        }
        return left;
    }
    
    bool islarger(vector<int>& nums, double mid, int k){
        double sum = 0, prev_sum = 0, min_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] - mid;
            if(i >= k){
                prev_sum += nums[i-k] - mid;                        
                min_sum = min(prev_sum, min_sum); 
            }
            if(i >= k-1 && sum > min_sum)return false;
        }
        return true;                                               
    }
};