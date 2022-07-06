class MajorityChecker {
private:
    unordered_map<int, vector<int>> pos;
    vector<int> a;
    int try_bound;
    
public:
    MajorityChecker(vector<int>& arr): a(arr) {
        for (int i = 0; i < arr.size(); ++i) {
            pos[arr[i]].push_back(i);
        }
        try_bound = 20;
    }
    
    int get_occurrence(int num, int l, int r) {
        auto iter = pos.find(num);
        if (iter == pos.end()) {
            return 0;
        }
        const auto& vec = iter->second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), l);
        if (iter_l == vec.end()) {
            return 0;
        }
        auto iter_r = upper_bound(vec.begin(), vec.end(), r);
        return iter_r - iter_l;
    }
    
    int get_random(int l, int r) {
        return rand() % (r - l + 1) + l;
    }
    
    int query(int left, int right, int threshold) {
        for (int i = 0; i < try_bound; ++i) {
            int elem = a[get_random(left, right)];
            if (get_occurrence(elem, left, right) >= threshold) {
                return elem;
            }
        }
        return -1;
    }
};