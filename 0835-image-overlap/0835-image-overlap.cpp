class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int rows = img1.size(), cols = img1[0].size();
        int maxCount = 0;
        for (int sr=0; sr<rows; ++sr) { // shift r
            for (int sc=0; sc<cols; ++sc) { // shift c
                maxCount = max(maxCount, countOverlap(img1, img2, sr, sc));  
                maxCount = max(maxCount, countOverlap(img1, img2, -sr, sc)); 
                maxCount = max(maxCount, countOverlap(img1, img2, sr, -sc)); 
                maxCount = max(maxCount, countOverlap(img1, img2, -sr, -sc));
            }
        }
        return maxCount;
    }
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int sr, int sc) {
        int rows = img1.size(), cols = img1[0].size();
        int count = 0;
        for (int r=0; r<rows; ++r) {
            for (int c=0; c<cols; ++c) {
                int nr = r + sr;
                int nc = c + sc;
                int pixel = (nr < 0 || nc < 0 || nr >= rows || nc >= cols) ? 0 : img1[nr][nc];
                if (pixel && pixel == img2[r][c]) count++;
            }
        }
        return count;
    }
};