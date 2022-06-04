class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set<pair<int, int>> ss; 
        unordered_map<int, int> rows, cols, anti, diag; 
        
        for (auto& lamp : lamps) {
            int i = lamp[0], j = lamp[1]; 
            if (ss.insert({i, j}).second) {
                ++rows[i]; ++anti[i+j]; 
                ++cols[j]; ++diag[i-j]; 
            }
        }
        
        vector<int> ans; 
        for (auto& query : queries) {
            int i = query[0], j = query[1]; 
            if (rows[i] || cols[j] || anti[i+j] || diag[i-j]) ans.push_back(1); 
            else ans.push_back(0); 
            for (int ii = i-1; ii <= i+1; ++ii) 
                for (int jj = j-1; jj <= j+1; ++jj) 
                    if (ss.erase({ii, jj})) {
                        --rows[ii]; --anti[ii+jj]; 
                        --cols[jj]; --diag[ii-jj]; 
                    }
        }
        return ans; 
    }
};