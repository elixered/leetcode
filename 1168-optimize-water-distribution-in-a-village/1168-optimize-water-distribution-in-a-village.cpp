class Solution {
public:
    class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        size = sz;
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void connect(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
        size--;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
        
        int getSize()
        {
            return size;
        }

private:
    int size;
    vector<int> root;
    vector<int> rank;
};
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=0; i<n; i++)
            pipes.push_back({0,i+1,wells[i]});
        sort(pipes.begin(),pipes.end(),[&](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        UnionFind uf(n+1);
        int cost = 0;
        for(auto pipe:pipes){
            if(!uf.connected(pipe[0],pipe[1])){
                cost += pipe[2];
                uf.connect(pipe[0],pipe[1]);
                if(uf.getSize() == 1) break;
            }
        }
        return cost;
    }
};