class SparseVector {
public:
    unordered_map<int,int> mp;
    SparseVector(vector<int> &nums) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i])
                mp[i] = nums[i];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for(auto it:mp){
            if(vec.mp.find(it.first)!=vec.mp.end())
                ans += mp[it.first]*vec.mp[it.first];
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);