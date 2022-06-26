class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int k = mat1[0].size();
        int m = mat2[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int ridx=0; ridx<n; ridx++){
            for(int eidx=0; eidx<k; eidx++){
                if(mat1[ridx][eidx] != 0){
                    for(int colidx=0; colidx<m; colidx++){
                        ans[ridx][colidx] += mat1[ridx][eidx]*mat2[eidx][colidx];
                    }
                }
            }
        }
        return ans;
    }
};