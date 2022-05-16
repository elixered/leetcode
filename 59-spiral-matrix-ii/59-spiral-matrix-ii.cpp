class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int curr = 1;
        int max = n*n;
        vector<vector<int>> ans(n,vector<int>(n));
        int dir = 0;
        int bottom = 0, top = n-1;
        int left  = 0, right = n-1;
        while(bottom <= top && left <= right)
        {
             if(dir==0)
            {
                for(int i=left;i<=right;i++)
                    ans[bottom][i] = curr++;
                bottom++;
            }
            else if(dir==1)
            {
                for(int i=bottom;i<=top;i++)
                    ans[i][right] = curr++;
                right--;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                    ans[top][i] = curr++;
                top--;
            }
            else if(dir==3)
            {
                for(int i=top; i>=bottom; i--)
                    ans[i][left] = curr++;
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};