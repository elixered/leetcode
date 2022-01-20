class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high-low+1>k)
        {
            if(abs(arr[low]-x)<=abs(arr[high]-x))
                high--;
            else
                low++;
        }
        return vector<int>(arr.begin()+low,arr.begin()+high+1);
    }
};