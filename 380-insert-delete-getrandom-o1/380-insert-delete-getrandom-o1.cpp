class RandomizedSet {
public:
    unordered_map<int,int> values;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(values.find(val) != values.end()) return false;
            nums.emplace_back(val);
            values[val] = nums.size()-1;
            return true;
    }
    
    bool remove(int val) {
        if(values.find(val)==values.end()) return false;
        int last = nums.back();
        values[last] = values[val];
        nums[values[val]] = last;
        nums.pop_back();
        values.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        int i = rand()%n;
        return nums[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */