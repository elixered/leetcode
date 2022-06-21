class SparseVector {
public:
    typedef pair<int,int> ppi;
    vector<ppi> arr;
    SparseVector(vector<int> &nums) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i])
                arr.push_back({i,nums[i]});
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i=0,j=0;
        int n = arr.size();
        int m = vec.arr.size();
        int ans = 0;
        while(i<n && j<m){
            cout<<i<<" "<<j<<" ";
            if(arr[i].first==vec.arr[j].first)
            {
                ans += arr[i].second*vec.arr[j].second;
                i++;
                j++;
            }
            else if(arr[i].first < vec.arr[j].first)
                i++;
            else j++;
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);