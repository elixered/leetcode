class Bitset {
public:
    vector<int> set;
    int cnt;
    bool flipped;
    Bitset(int size) {
        set = vector<int>(size,0);
        cnt = 0;
        flipped = false;
    }
    
    void fix(int idx) {
        if(!flipped)
        {
        if(set[idx]==0) cnt++;
        set[idx] = 1;
        }
        else
        {
            if(set[idx]==1) cnt++;
            set[idx] = 0;
        }
        
    }
    
    void unfix(int idx) {
        if(!flipped)
        {
        if(set[idx]==1)
            cnt--;
        set[idx] = 0;
        }
        else
        {
            if(set[idx]==0)
                cnt--;
            set[idx] = 1;
        }
    }
    
    void flip() {
        flipped = !flipped;
        cnt = set.size() - cnt;
    }
    
    bool all() {
        return cnt == set.size();
    }
    
    bool one() {
        return cnt >= 1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string ans;
        for(int i=0; i<set.size(); i++)
        {
            int idx = i;
            int it = set[i];
            if(flipped) it = 1-it;
            ans += to_string(it);
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */