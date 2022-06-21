class SparseVector {
public:
    vector<int> arr;
    SparseVector(vector<int> &nums) {
        arr = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++)
            ans += vec.arr[i]*arr[i];
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);