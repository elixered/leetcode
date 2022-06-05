class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> ht;
    list<int> dll;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    void moveToFirst(int key){
        dll.erase(ht[key].first);
        dll.push_front(key);
        ht[key].first=dll.begin();
    }
    
    int get(int key) {
        if(ht.find(key)==ht.end()) return -1;
        
        moveToFirst(key);
        return ht[key].second;
    }
    
    void put(int key, int value) {
        if(ht.find(key)!=ht.end()){
            ht[key].second=value;
            moveToFirst(key);
        }
        else{
            dll.push_front(key);
            ht[key]={dll.begin(), value};
            cap--;
        }
        
        if(cap<0){
            ht.erase(dll.back());
            dll.pop_back();
            cap++;
        }
        
    }
};