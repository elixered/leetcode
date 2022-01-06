class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int hi = matrix.size()*matrix[0].size()-1;
        
        int c = matrix[0].size();
        
        int lo = 0;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(matrix[mid/c][mid%c]==target)
                return true;
            else
                if(target < matrix[mid/c][mid%c])
                   hi = mid-1;
            else lo = mid+1;
        }
        return false;
    }
};