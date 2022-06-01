class Solution {
public:
    struct compare{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second < b.second;
        }
    } compare;
	
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
	// Step 1
        unordered_map<int, int> map;
        for(int a: arr)
            map[a]++;
			
	// Step 2
        vector<pair<int, int>> vec;
        for(auto a: map)
        {
            vec.push_back({a.first, a.second});
        }
        sort(vec.begin(), vec.end(), compare);
	
	// Step 3
        auto it = vec.begin();
        int res = vec.size();
        while(it != vec.end() && k-- > 0)
        {
            it->second--;
            if(it->second == 0)
            {
                it++;
                res--;
            }
        }
        return res;            
    }
};