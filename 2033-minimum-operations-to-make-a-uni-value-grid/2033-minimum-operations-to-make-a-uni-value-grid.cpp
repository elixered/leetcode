class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<int> arr;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                arr.push_back(grid[i][j]);
        
        sort(arr.begin(),arr.end());
        int median = arr[(m*n)/2];
        
        for(auto it:arr)
        {
            if(abs(it-median)%k != 0) return -1;
            else count += abs(it-median)/k;
        }
        return count;
    }
};