class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        auto min_start = INT_MAX, max_end = INT_MIN;
        for (const auto& row : paint) {
            min_start = min(min_start, row[0]);
            max_end = max(max_end, row[1]);
        }
        
        set<int> painting;
        for (int i = min_start; i < max_end; ++i)
            painting.insert(i);
        
        vector<int> res;
        res.reserve(paint.size());
        for (const auto& row : paint) {
            int count = 0;
            auto it = painting.lower_bound(row[0]);
            while (it != painting.end() && *it < row[1]) {
                it = painting.erase(it);
                ++count;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
};