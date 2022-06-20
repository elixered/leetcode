class HitCounter {
public:
    deque<pair<int,int>> dq;
    int hits = 0;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        if(dq.empty() or dq.back().first<timestamp)
            dq.push_back({timestamp,1});
        else (&dq.back())->second++;
        hits++;
    }
    
    int getHits(int timestamp) {
        while(!dq.empty() && dq.front().first <= timestamp-300){
            hits -= dq.front().second;
            dq.pop_front();
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