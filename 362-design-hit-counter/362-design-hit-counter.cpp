class HitCounter {
public:
    int hits;
    map<int,int> mp;
    HitCounter() {
        hits = 0;
    }
    
    void hit(int timestamp) {
        hits++;
        mp[timestamp]++;
    }
    
    int getHits(int timestamp) {
        auto itr = mp.begin();
        while(itr!=mp.end() && itr->first <=timestamp-300){
            auto curr = itr;
            itr = next(itr);
            hits -= curr->second;
            mp.erase(curr);
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */