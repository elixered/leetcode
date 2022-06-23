class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        auto res = mp.find(val) == mp.end();
        mp[val].insert(nums.size());
        nums.push_back(val);
        return res;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int idx = *(mp[val].begin());
        mp[val].erase(idx);
        if(mp[val].empty())
            mp.erase(val);
        if(idx != nums.size()-1){
            auto last = nums.back();
            nums[idx] = last;
            mp[last].erase(nums.size()-1);
            mp[last].insert(idx);
        }
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */