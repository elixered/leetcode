class Solution {
public:    
    void update(vector<int>& bit,int n,int x, int delta)
    {
        for(; x<=n; x += x&-x)
            bit[x] += delta;
    }
    int sum(vector<int>& bit,int x)
    {
        int s = 0;
        for(; x>0; x -= x&-x)
            s += bit[x];
        return s;
    }
    int numTeams(vector<int>& arr) {
        int n = arr.size();
        int m = *max_element(arr.begin(),arr.end());
        vector<int> right(m+1,0),left(m+1,0);
        
        for(int i=0;i<n;++i)
            update(right, m, arr[i], 1);
        
         int ans = 0, l, r;
        
         for(int i=0;i<n;++i)
         {
             update(right, m, arr[i], -1);
             
            //smaller to left
            l = sum(left, arr[i]-1);
            //greter to right
            r = sum(right, m) - sum(right, arr[i]);
            
             ans += l*r;
             
            //larget to left
            l = sum(left, m) - sum(left, arr[i]);
            //smaller to right
            r = sum(right, arr[i] -1);
             
            ans += l*r;
            
            update(left, m, arr[i], 1);
         }
        return ans;
    }
};