class Solution {
public:
    
    void merge(vector<long>& nums, int l, int r){
        if(l >= r) return;
        vector<long> temp(r-l+1,0);
        int m = (l+r)/2;
        int i=l,j=m+1,k=0;
        while(i<=m && j<=r)
        {
            if(nums[i]<nums[j])
                temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i<=m)
            temp[k++] = nums[i++];
        while(j<=r)
            temp[k++] = nums[j++];
        for(int x=l; x<=r; x++)
            nums[x] = temp[x-l];
    }
    
    int mergeSort(vector<long>& nums, int l, int r, int lower, int upper){
        if(l > r) return 0;
        if(l == r) return nums[l] >= lower && nums[l] <= upper;
        int mid = (l+r)/2;
        int count = 0;
        count += mergeSort(nums,l,mid,lower,upper);
        count += mergeSort(nums,mid+1,r,lower,upper);
        int i = mid+1, j = mid+1;
        for (int k = l; k <= mid; k++) {
			while (i <= r && nums[i] - nums[k] < lower) i++;  
			while (j <= r && nums[j] - nums[k] <= upper) j++;
			count += j - i;
		}
        merge(nums,l,r);
        return count;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> psum(n,0);
        psum[0] = nums[0];
        for(int i=1; i<n; ++i)
            psum[i] += psum[i-1] + nums[i];
        return mergeSort(psum,0,n-1,lower,upper);
    }
};