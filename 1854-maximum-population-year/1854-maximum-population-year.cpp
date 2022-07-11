class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        vector<int>v(2051,0);
        
        for(auto a:logs){
            v[a[0]]+=1;
            v[a[1]]-=1;
        }
        for(int i=1;i<2051;i++){
            v[i]+=v[i-1];
        }
        
        int a=INT_MIN,ans=0;
        for(int i=0;i<2051;i++){
            if(a<v[i])a=v[i],ans=i;
        }
        return ans;
    }
};