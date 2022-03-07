class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int,int> map;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int curr = matrix[i][j];
                if(map.find(i-j) == map.end())
                    map[i-j]= curr;
                if(curr != map[i-j]) return false;
            }
        }
        return true;
    }
};