class Solution {
public:
    
    int partition(vector<int>& nums, int l, int r){
        int sidx = l + (rand())%(r-l+1);
        swap(nums[r],nums[sidx]);
        int pidx = l;
        int pivot = nums[r];
        for(int i=l; i<r; ++i){
            if(nums[i] <= pivot){
                swap(nums[i],nums[pidx++]);
            }
        }
        swap(nums[pidx],nums[r]);
        return pidx;
    }
    
    void quickSort(vector<int>& nums, int l, int r){
        if(l>=r) return;
        int m = partition(nums,l,r);
        quickSort(nums,l,m-1);
        quickSort(nums,m+1,r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};