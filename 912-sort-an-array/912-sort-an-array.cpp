class Solution {
public:
    
    void merge(vector<int>& nums, int l, int r){
        if(l>=r) return;
        int m = (l+r)/2;
        vector<int> temp(r-l+1);
        int i=l,j=m+1;
        int idx = 0;
        while(i<=m && j<=r){
            if(nums[i] < nums[j]){
                temp[idx++] = nums[i++];
            }
            else temp[idx++] = nums[j++];
        }
        while(i<=m)
            temp[idx++] = nums[i++];
        while(j<=r)
            temp[idx++] = nums[j++];
        for(int i=l; i<=r; i++)
            nums[i] = temp[i-l];
    }
    
    void mergeSort(vector<int>& nums, int l, int r){
        if(l>=r) return;
        int m = (l+r)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,r);
        merge(nums,l,r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};