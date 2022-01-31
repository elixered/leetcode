class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(auto& row:accounts)
        {
            int temp = 0;
            for(auto& col:row)
            {
                temp += col;
            }
            maxi = max(maxi,temp);
        }
        return maxi;
    }
};