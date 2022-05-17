class Solution {
public:
    int fun(vector<int>& arr, int n) { 
        int max_sum = arr[0], min_sum = arr[0];  
        for (int i = 0; i < n; i++) { // Finding max and min sum value 
            max_sum=max(max_sum,arr[i]);
            min_sum=min(min_sum,arr[i]);
        } 
        return (max_sum-min_sum); 
    } 
    
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> sum1(n,0),diff1(n,0),sum2(n,0),diff2(n,0);
        for(int i=0;i<n;i++) {
            sum1[i]=arr1[i]+arr2[i]+i;
            diff1[i]=arr1[i]-arr2[i]+i;
            sum2[i]=arr1[i]+arr2[i]-i;
            diff2[i]=arr1[i]-arr2[i]-i;
        }
        return max(max(fun(sum1,n),fun(diff1,n)),max(fun(sum2,n),fun(diff2,n)));        
    }
};