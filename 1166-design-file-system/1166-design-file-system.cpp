class FileSystem {
public:
    unordered_map<string,int> mp;
    FileSystem() {
        mp[""] = 1;
    }
    
    bool createPath(string path, int value) {
        if(mp.find(path) != mp.end()) return false;
        int n = path.size();
        if(n<=1 or path[0]!='/') return false;
        string s = path;
        while(s.size() && s.back()!='/') s.pop_back();
        if(s.size()) s.pop_back();
        if(mp.find(s) == mp.end()) return false;
        mp[path] = value;
        return true;
    }
    
    int get(string path) {
        return mp.find(path) == mp.end() ? -1:mp[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */