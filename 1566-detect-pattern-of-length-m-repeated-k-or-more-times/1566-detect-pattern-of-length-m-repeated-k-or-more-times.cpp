class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0; i+m<n; ++i){
            if(arr[i] == arr[i+m]){
                cnt++;
                if(cnt == (k-1)*m)
                    return true;
            }
            else 
                cnt = 0;
        }
        return false;
    }
};