class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& v1, const vector<int>& v2)
        {
            return v1[2] < v2[2];
        }
    };
    
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                ans.push_back({i,j,abs(rCenter-i)+abs(cCenter-j)});
            }
        }
        sort(ans.begin(),ans.end(),cmp());
        for(auto& row:ans)
            row.pop_back();
        return ans;
    }
};