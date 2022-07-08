class Solution {
public:
    
    class UnionFind{
    private:
        vector<int> rank;
        vector<int> root;
        int size;
    public:
        UnionFind(int sz){
            size = sz;
            rank.resize(sz);
            root.resize(sz);
            for(int i=0; i<sz; ++i){
                root[i] = i;
                rank[i] = 1;
            }
        }
        
        int find(int x){
            if(root[x] == x)
                return x;
            else return root[x] = find(root[x]);
        }
        
        void connect(int x, int y){
            int rootX = root[x];
            int rootY = root[y];
            if(rootX != rootY){
                if(rank[rootX] > rank[rootY]){
                    root[rootY] = rootX;
                }
                else if(rank[rootY] > rank[rootX]){
                    root[rootX] = rootY;
                }
                else{
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
                size--;
            }
        }
        
        bool connected(int x, int y){
            return find(x) == find(y);
        }
        
        int getSize(){
            return size;
        }
    };
    
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        int n = row.size();
        UnionFind uf(n);
        for(int i=0; i<n; i+=2)
            uf.connect(row[i],row[i+1]);
        for(int i=0; i<n; i+=2){
            if(!uf.connected(i,i+1)){
                res++;
                uf.connect(i,i+1);
            }
        }
        return res;
    }
};