class TimeMap {
public:
    unordered_map<string,map<int,string>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto itr = map[key].upper_bound(timestamp);
        return itr == map[key].begin()?"":prev(itr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */