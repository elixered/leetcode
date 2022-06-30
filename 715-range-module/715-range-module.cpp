class RangeModule {
private:
    map<int,int> mp;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto l = mp.upper_bound(left);
        if(l != mp.begin() && prev(l)->second >= left)
            left = prev(l)->first;
        right = removeIntervals(left,right);
        mp[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if(it != mp.begin())
            it = prev(it);
        return it->first <= left && it->second >= right;
    }
    
    void removeRange(int left, int right) {
        int right1 = removeIntervals(left,right);
        auto it = mp.upper_bound(left);
        if(it != mp.begin()){
            right1 = max(right1, prev(it)->second);
            prev(it)->second = min(prev(it)->second, left);
        }
        if(right1 > right)
            mp[right] = right1;
    }
    
    int removeIntervals(int left, int right){
        auto it = mp.lower_bound(left);
        for(it; it!=mp.end() && it->first <= right; ){
            right = max(right,it->second);
            mp.erase(it++);
        }
        return right;
    }
    
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */