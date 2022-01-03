class MyHashMap {
public:
    vector<int> hm;
    int sz = 10000001;
    MyHashMap() {
        hm.resize(sz,-1);
    }
    
    void put(int key, int value) {
        hm[key%sz] = value;
    }
    
    int get(int key) {
        return hm[key%sz];
    }
    
    void remove(int key) {
        hm[key%sz] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */