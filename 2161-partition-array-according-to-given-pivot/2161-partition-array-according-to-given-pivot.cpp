class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0;
        int equal = 0;
        for(auto& n:nums)
        {
            if(n<pivot)
                less++;
            else if(n==pivot)
                equal++;
        }
        int l = 0;
        int m = less;
        int h = less+equal;
        vector<int> res(nums.size());
        for(auto& n:nums)
        {
            if(n<pivot)
                res[l++] = n;
            else if(n==pivot)
                res[m++] = n;
            else res[h++] = n;
        }
        return res;
    }
};