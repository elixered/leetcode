class Solution {
public:
    
    void build(vector<int>& arr, vector<int>& prefix, int target){
        int i = 0, j = 0;
        int sum = 0;
        int sz = 1e7;
        while(j < arr.size()){
            sum += arr[j];
            while(i <= j && sum > target)
                sum -= arr[i++];
            if(sum == target){
                sz = min(sz,j-i+1);
            }
            prefix[j] = sz;
            ++j;
        }
    }
    
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n,-1),suffix(n,-1);
        build(arr,prefix,target);
        reverse(begin(arr), end(arr));
        build(arr,suffix,target);
        reverse(begin(suffix),end(suffix));
        int ans = 1e7;
        for(int i=0; i<n-1; ++i){
            ans = min(ans,prefix[i]+suffix[i+1]);
        }
        return ans == 1e7 ? -1 : ans;
    }
};