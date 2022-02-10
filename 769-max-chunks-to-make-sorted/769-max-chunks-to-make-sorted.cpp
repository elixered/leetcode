class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        int count = 0;
        while(i<n)
        {
            if(arr[i]==i)
            {
                count++;
                i++;
            }
            else
            {
                int imin = INT_MAX, imax = INT_MIN;
                int nmin = INT_MAX, nmax = INT_MIN;
                while(i<n)
                {
                    imin = min(i,imin);
                    imax = max(i,imax);
                    nmin = min(nmin,arr[i]);
                    nmax = max(nmax,arr[i]);
                    if(imin==nmin && imax==nmax)
                    {
                        count++;
                        i++;
                        break;
                    }
                    else i++;
                }
            }
        }
        return count;
    }
};