class SmallestInfiniteSet {
public:
    int smallest = 1;
    set<int> st;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int t = smallest;
        if(!st.empty()){
            t = *st.begin();
            st.erase(st.begin());
            return t;
        }
        return smallest++;
    }
    
    void addBack(int num) {
        if(num < smallest)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */