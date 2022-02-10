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
                vector<int> indices(n);
                vector<int> nums(n);
                while(i<n)
                {
                    indices[i]++;
                    nums[arr[i]]++;
                    if(indices==nums)
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