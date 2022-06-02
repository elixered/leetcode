class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans(votes[0]);
        const int n(votes[0].length());
        vector<vector<int>> ranks(26, vector<int>(n));
        
        for (const string& vote: votes)
            for (int i = 0; i < n; ++i)
                ranks[vote[i] - 'A'][i]++;

        function<bool(const char&, const char&)> compare = [&](const char& x, const char& y) {
            for (int i = 0; i < n; ++i) {
                if (ranks[x - 'A'][i] == ranks[y - 'A'][i]) continue;
                return ranks[x - 'A'][i] > ranks[y - 'A'][i];
            }
            return x < y;
        };
        
        sort(ans.begin(), ans.end(), compare);
		
        return ans;
    }
};