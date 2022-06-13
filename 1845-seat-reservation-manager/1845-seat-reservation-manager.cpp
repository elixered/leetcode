class SeatManager {
public:
    vector<int> reserved;
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        reserved.resize(n+1,0);
        for(int i=1; i<=n; i++)
            pq.push(i);
    }
    
    int reserve() {
        auto idx = 1;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            if(!reserved[it])
            {
                idx = it;
                break;
            }
        }
        reserved[idx] = 1;
        return idx;
    }
    
    void unreserve(int seatNumber) {
        reserved[seatNumber] = 0;
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */