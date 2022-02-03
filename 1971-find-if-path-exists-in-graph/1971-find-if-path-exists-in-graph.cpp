class Solution {
public:
    class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int sz)
    {
        parent = vector<int>(sz);
        rank = vector<int>(sz,1);
        for(int i=0; i<sz; i++)
            parent[i] = i;
    }
void unionset(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(rank[x]>rank[y])
    {
        parent[y] = x;
    }
    else if(rank[x]<rank[y])
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
        rank[x]++;
    }
}
int find(int x)
{
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool connected(int x, int y)
{
    return find(x) == find(y);
}
};
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind dsu(n);
        for(auto &it:edges)
            dsu.unionset(it[0],it[1]);
        return dsu.find(source) == dsu.find(destination);
    }
};