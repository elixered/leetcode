class Solution {
public:
    int help(map<pair<int,int>,int>&m,int prev,int i,vector<int>& arr1, vector<int>& arr2)
    {
        if(i==arr1.size())return 0;
        if(m.find({i,prev})!=m.end())return m[{i,prev}];
        int ans=INT_MAX/2;
        int f=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(arr1[i]>prev)ans=min(ans,help(m,arr1[i],i+1,arr1,arr2));
        if(f<arr2.size())ans=min(ans,help(m,arr2[f],i+1,arr1,arr2)+1);
        return m[{i,prev}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> m;
        int ans= help(m,INT_MIN,0,arr1,arr2);
        return ans>=INT_MAX/4?-1:ans;
    }
};