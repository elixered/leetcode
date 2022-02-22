class Solution {
public:
    
    int merge(vector<int>& nums, int l, int r)
    {
        if(l>=r) return 0;
        int m = l + (r-l)/2;
        int low = l, high = r, i = l, j = m+1;
        vector<int> temp(high-low+1);
        int k = 0;
        int count = 0;
        int ans = 0;
        while(i<=m && j<=r)
        {
            if(nums[i] <= (long)2*nums[j])
            {
                ans += count;
                i++;
            }
            else
            {
                count++;
                j++;
            }
        }
        while(i<=m)
        {
            ans += count;
            i++;
        }
        i=l,j=m+1;
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
        return ans;
    }
    
    int merge_sort(vector<int>& nums, int l, int r)
    {
        if(l>=r) return 0;
        int m = l + (r-l)/2;
        int ans = 0;
        ans += merge_sort(nums,l,m);
        ans += merge_sort(nums,m+1,r);
        ans += merge(nums,l,r);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(nums,0,n-1);
    }
};