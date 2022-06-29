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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        };
        sort(edges.begin(),edges.end(),cmp);
        int querySize = queries.size();
        for(int i=0; i<querySize; ++i)
            queries[i].push_back(i);
        vector<bool> ans(querySize);
        sort(queries.begin(),queries.end(),cmp);
        UnionFind uf(n);
        int i = 0;
        int j = 0;
        for(int j=0; j<querySize; ++j){
            while(i < edges.size() && edges[i][2] < queries[j][2]){
                if(!uf.connected(edges[i][0],edges[i][1]))
                    uf.connect(edges[i][0],edges[i][1]);
                i++;
            }
            ans[queries[j][3]] = uf.connected(queries[j][0],queries[j][1]);
        }
        return ans;
    }
};