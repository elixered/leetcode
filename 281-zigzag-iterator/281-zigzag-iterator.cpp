class ZigzagIterator {
public:
    vector<vector<int>> v;
    queue<pair<int,int>> q;
    int sz;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        q.push({0,0});
        q.push({1,0});
        v.push_back(v1);
        v.push_back(v2);
        sz = v1.size()+v2.size();
    }

    int next() {
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            if( f.second < v[f.first].size()){
                q.push({f.first,f.second+1});
                sz--;
                return v[f.first][f.second];
            }
        }
        return -1;
    }

    bool hasNext() {
        return sz>0;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */