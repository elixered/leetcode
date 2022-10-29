class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        
        int nextBig[n+4];
        nextBig[n-1]=n;
        nextBig[n]=n;
        for(int i=n-1; i>=0; i--)
        {
            int pos;
            pos = i+1;
            while(pos<n && nums[pos]<= nums[i]  ){
                pos = nextBig[pos];
            }
            nextBig[i]=pos;
        }
        vector<int>ans(n);
        int pos;
        for(int i=0; i<n; i++)
        {
            pos = nextBig[i];
            pos++;
           
            while(pos<n && nums[pos]<=nums[i]){
                pos = nextBig[pos];
            }
           
                
            if(pos<n) ans[i]=nums[pos];
            else ans[i]=-1;
        }
        
        
        return ans;
    }
};
