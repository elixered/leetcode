class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> map(1001,0);
        for(auto it:trips)
        {
            map[it[1]] += it[0];
            map[it[2]] -= it[0];
        }
        int sum = 0;
        for(auto it:map)
        {
            sum += it;
            if(sum > capacity)
                return false;
        }
        return true;
    }
};