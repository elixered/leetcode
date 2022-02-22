class Solution {
public:
    
struct BIT{
    vector<int> bit;
    int n;
    BIT(){
        n = 1e4 * 2 + 2;
        bit.assign(n, 0);
    }        
    void update(int idx, int val){
        while(idx < n){
            bit[idx]+=val;
            idx += idx&-idx;
        }
    }
	
    
    int query(int idx){
        int s = 0;
        while(idx > 0){
            s += bit[idx];
            idx -= idx&-idx;
        }
        return s;
    }
};

int getidx(int idx){
    return idx + 1e4+1;
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,0);
    BIT bit;
    for(int i=n-1; i>=0; i--)
    {
        ans[i] = bit.query(getidx(nums[i])-1);
        bit.update(getidx(nums[i]),1);
    }
    return ans;
    
}
};