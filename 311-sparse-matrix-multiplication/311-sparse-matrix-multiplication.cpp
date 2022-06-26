class Solution {
public:
    vector<vector<pair<int, int>>> compressMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<pair<int, int>>> compressedMatrix(rows);
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] != 0) {
                    compressedMatrix[row].push_back({matrix[row][col], col}); 
                }
            }
        }
        return compressedMatrix;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        
        // Store the non-zero values of each matrix.
        vector<vector<pair<int, int>>> A = compressMatrix(mat1);
        vector<vector<pair<int, int>>> B = compressMatrix(mat2);
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for (int mat1Row = 0; mat1Row < m; ++mat1Row) {
            // Iterate on all current 'row' non-zero elements of mat1.
            for (auto [element1, mat1Col] : A[mat1Row]) {

                // Multiply and add all non-zero elements of mat2
                // where the row is equal to col of current element of mat1.
                for (auto [element2, mat2Col] : B[mat1Col]) {
                    ans[mat1Row][mat2Col] += element1 * element2;
                }
            }
        }
        
        return ans;
    }
};