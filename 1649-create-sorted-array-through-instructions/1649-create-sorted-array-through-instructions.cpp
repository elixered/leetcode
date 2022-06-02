class Solution {
public:
    int n;
    vector<int>seg;
    
    int query(int index,int low,int high,int l,int r)
    {
        if(low>=l && high<=r)
        {
            return seg[index];
        }
        if(high<l || low>r)
            return 0;
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return left+right;
    }
    
    void build(int index,int low,int high,vector<int>&nums)
    {
        if(low==high)
        {
            seg[index]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*index+1,low,mid,nums);
        build(2*index+2,mid+1,high,nums);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    
    void updt(int v, int l, int r, int idx,int val)
    {
        if(l>r) return;
        if(l==r && idx==l)
        {
            seg[v] = val;
            return;
        }
        int m = (l+r)/2;
        if(idx<=m)
        updt(2*v+1,l,m,idx,val);
        else if(idx>m)
        updt(2*v+2,m+1,r,idx,val);
        seg[v] = seg[2*v+1]+seg[2*v+2];
    }
    
    int createSortedArray(vector<int>& ins) {
        n = pow(10,5)+1;
        seg.resize(n*4,0);
        int ans = 0;
        map<int,int> map;
        int mod = 1e9+7;
        for(auto it:ins)
        {
            map[it]++;
            int a = query(0,0,n-1,0,it-1);
            int c = query(0,0,n-1,it+1,n-1);
            updt(0,0,n-1,it,map[it]);
            ans += min(a,c);
            ans %= mod;
        }
        return ans;
    }
};