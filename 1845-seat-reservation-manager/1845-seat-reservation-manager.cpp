class SeatManager {
public:
    
    bitset<100000> res;
    SeatManager(int n) {
        res.set(); // set all the bits
    }
    
    int reserve() {
        int pos = res._Find_first(); //find the first bit set
        res.reset(pos); // reset this to zero, as it is reserved.
        return pos+1;
    }
    
    void unreserve(int seatNumber) {
        
        res.set(seatNumber-1); // set it to on again, as sit is available.
    }
};