class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        int idx = 0;
        while(idx<n-1)
        {
            if(arr[idx]<arr[idx+1])
                idx++;
            else
                if(arr[idx]>arr[idx+1])
                    break;
            else
                return false;
        }
        if(idx==0 or idx==n-1)
            return false;
        idx++;
        while(idx<n)
        {
            if(arr[idx]<arr[idx-1])
                idx++;
            else return false;
        }
        return true;
    }
};