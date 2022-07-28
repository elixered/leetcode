class Solution {
public:
    vector<int>f;
    bool isconnect(int a,int b,int x){
        if(x == 0){
            if((a == 1 || a == 3 || a == 5) && (b == 1 || b == 4 || b == 6)) return true;
            return false;
        }
        if((a == 2 || a == 5 || a == 6) && (b == 2 || b == 3 || b == 4)) return true;
        return false;
    }
    int find(int x){
        if(f[x] != x) 
            return f[x] = find(f[x]);
        return x;
    }
    void uni(int x,int y){
        f[find(x)] = f[y];
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int r = grid.size(),c = grid[0].size();
        f.resize(r*c);
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++) f[i*c+j] = i*c+j;
        }
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(i>0 && j>0){
                    if(isconnect(grid[i][j],grid[i-1][j],1)&&isconnect(grid[i][j],grid[i][j-1],0)){
                        uni((i-1)*c+j,i*c+j-1);
                        f[i*c+j] = find(f[(i-1)*c+j]);
                    }
                    else if(isconnect(grid[i][j],grid[i-1][j],1)){
                        f[i*c+j] = find(f[(i-1)*c+j]);
                    }
                    else if(isconnect(grid[i][j],grid[i][j-1],0)){
                        f[i*c+j] = find(f[i*c+j-1]);
                    }
                }
                else if(i>0){
                    if(isconnect(grid[i][j],grid[i-1][j],1)){
                        f[i*c+j] = find(f[(i-1)*c+j]);
                    }
                }
                else if(j>0){
                    if(isconnect(grid[i][j],grid[i][j-1],0)){
                        f[i*c+j] = find(f[i*c+j-1]);
                    }
                }
            }
        }
        return find(0) == find(r*c-1);
    }
};