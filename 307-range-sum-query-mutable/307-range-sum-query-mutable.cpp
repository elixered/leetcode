class NumArray {
public:
    vector<int> nums;
    vector<int> bit;
    int n;
    NumArray(vector<int>& num) {
        n = num.size();
        nums = vector<int>(n,0);
        bit = vector<int>(n+1,0);
        for(int i=0; i<n; i++)
            update(i,num[i]);
        nums = num;
    }

    
    void update(int index, int val) {
        int idx = index+1;
        for(idx; idx<=n; idx += (idx&(-idx)))
            bit[idx] += val-nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
    }
    
    int sum(int idx)
    {
        int ans = 0;
        for(int i=idx; i>0; i-=(i&(-i)))
            ans += bit[i];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */