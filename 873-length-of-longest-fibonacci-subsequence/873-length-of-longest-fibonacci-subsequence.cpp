class Solution {
public:
    
    unordered_map<int,unordered_map<int,int>> mp;
    
    int solve(vector<int>& arr, int idx, int first, int second){
        if(idx == arr.size()) return 0;
        if(mp[idx].find(first+second) != mp[idx].end()) return mp[idx][first+second];
        auto itr = lower_bound(arr.begin()+idx,arr.end(),first+second);
        if(itr != arr.end() && *itr == first+second)
            return mp[idx][first+second] = solve(arr,itr-arr.begin()+1,second,first+second)+1;
        else return 0;
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n-2; ++i){
            for(int j=i+1; j<n-1; ++j){
                ans = max(ans,solve(arr,j+1,arr[i],arr[j]));
            }
        }
        return ans+2>=3?ans+2:0;
    }
};