class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size();
        int n = image[0].size();
        for(int i=0; i<m; i++)
        {
            int j=0, k = n-1;
            while(j<k)
            {
                image[i][j] = 1-image[i][j];
                image[i][k] = 1-image[i][k];
                swap(image[i][j++],image[i][k--]);
            }
          if(j==k) image[i][j] = 1-image[i][j];
        }
        return image;
    }
};