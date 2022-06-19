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
    int minimumCost(int n, vector<vector<int>>& c) {
        UnionFind uf(n+1);
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[2]<b[2];
        };
        int ans = 0;
        sort(c.begin(),c.end(),cmp);
        int count = 1;
        for(auto& e:c){
            if(!uf.connected(e[0],e[1])){
                uf.connect(e[0],e[1]);
                ans += e[2];
                count++;
            }
        }
        return count==n?ans:-1;
    }
};