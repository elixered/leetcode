class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1,0);
        for(auto& it:bookings)
        {
            ans[it[0]-1] += it[2];
            ans[it[1]] -= it[2];
        }
        for(int i=1; i<=n; i++)
            ans[i] += ans[i-1];
        ans.pop_back();
        return ans;
    }
};