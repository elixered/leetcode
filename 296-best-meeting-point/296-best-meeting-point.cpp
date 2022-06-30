class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ex;
        vector<int> why;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]){
                    ex.push_back(i);
                    why.push_back(j);
                }
            }
        }
        sort(begin(ex),end(ex));
        sort(begin(why),end(why));
        n = ex.size();
        int median;
        if(n%2 == 0) median = (ex[n/2]+ex[n/2-1])/2;
        else median = ex[n/2];
        int ans = 0;
        for(auto e:ex)
            ans += abs(e-median);
        if(n%2 == 0) median = (why[n/2]+why[n/2-1])/2;
        else median = why[n/2];
        for(auto e:why)
            ans += abs(e-median);
        return ans;
    }
};