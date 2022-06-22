class Vector2D {
public:
    stack<pair<vector<int>::iterator,vector<int>::iterator>> st;
    Vector2D(vector<vector<int>>& vec) {
        for(int i=vec.size()-1; i>=0; i--){
            auto& it = vec[i];
            if(it.begin() != it.end())
            st.push({it.begin(),it.end()});
        }
    }
    
    int next() {
        auto f = st.top().first;
        auto e =st.top().second;
        st.pop();
        if(f+1 != e){
            st.push({f+1,e});
        }
        return *f;
    }
    
    bool hasNext() {
        return st.size() > 0;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */