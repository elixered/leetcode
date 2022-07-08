class NumMatrix {
public:
    vector<vector<int>> bit,matrix;
    int m,n;
    void updt(int r, int c, int val){
        r++;
        c++;
        int i,j;
        for(i=r; i<=m; i+=(i&(-i))){
            for(j=c; j<=n; j+=(j&(-j))){
                bit[i][j] += val;
            }
        }
    }
    
    int sum(int r, int c){
        int res = 0;
        int i = r, j = c;
        for(i=r; i>0; i-=(i&(-i))){
            for(j=c; j>0; j-=(j&(-j))){
                res += bit[i][j];
            }
        }
        return res;
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
        bit = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                updt(i,j,matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        updt(row,col,val-matrix[row][col]);
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int a = sum(row2,col2);
        int b = sum(row1-1,col1-1);
        int c = sum(row1-1,col2);
        int d = sum(row2,col1-1);
        return a+b-(c+d);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */