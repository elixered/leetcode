class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adjMatrix(n, vector<int>(n));
        for (int i = 0; i < prerequisites.size(); ++i){
            adjMatrix[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }
        
        FloydWarshall(n, adjMatrix);
        vector<bool> ans;
        
        for (int i = 0; i < queries.size(); ++i){
            ans.push_back(adjMatrix[queries[i][0]][queries[i][1]]);
        }
        
        return ans;
        
    }
    
    void FloydWarshall(int n, vector<vector<int>>& m){
        
        for (int k = 0; k < n ; ++k){
            for (int i = 0; i < n ; ++i){
                for (int j = 0; j < n ; ++j){
                    m[i][j] = m[i][j] or (m[i][k] and m[k][j]);
                }
            }
        }
    }
};