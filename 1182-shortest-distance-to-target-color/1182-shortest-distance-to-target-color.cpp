class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& color, vector<vector<int>>& queries) {
        int n = color.size();
        vector<vector<int>> left(n,vector<int>(4,1e5)), right(n,vector<int>(4,3e5));
        left[0][color[0]] = 0;
        for(int i=1; i<n; ++i){
            for(int j=1; j<=3; ++j){
                left[i][j] = min(left[i][j],left[i-1][j]+1);
            }
            left[i][color[i]] = 0;
        }
        right[n-1][color[n-1]] = 0;
         for(int i=n-2; i>=0; --i){
            for(int j=1; j<=3; ++j){
                right[i][j] = min(right[i][j],right[i+1][j]+1);
            }
            right[i][color[i]] = 0;
        }
        vector<int> ans;
        for(auto v:queries)
            ans.push_back(min(left[v[0]][v[1]],right[v[0]][v[1]]));
        for(auto& it:ans)
            if(it >= 1e5) it = -1;
        return ans;
    }
};