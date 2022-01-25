class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i]==0)
            {
                int j = n-1;
                while(j>i)
                {
                    arr[j] = arr[j-1];
                    j--;
                }
            }
        }
    }
};