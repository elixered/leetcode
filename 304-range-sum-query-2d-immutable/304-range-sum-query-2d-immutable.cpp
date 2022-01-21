class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        accu = matrix;
        for (int i=0; i<matrix.size(); ++i)
            for (int j=0; j<matrix[0].size(); ++j)
                accu[i][j] += a(i-1, j) + a(i, j-1) - a(i-1, j-1);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return a(row2, col2) - a(row1-1, col2) - a(row2, col1-1) + a(row1-1, col1-1);
    }

private:
    vector<vector<int>> accu;
    int a(int i, int j) {
        return i >= 0 && j >= 0 ? accu[i][j] : 0;
    }
};