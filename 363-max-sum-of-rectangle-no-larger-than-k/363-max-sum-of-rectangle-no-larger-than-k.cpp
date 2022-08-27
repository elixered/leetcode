class Solution {
public:
    int m, n, K, result = INT_MIN;
    void updateResult(vector<int> nums){
        int sum=0;
        set<int> s;
        s.insert(sum);
        for(int num : nums){
            sum+=num;
            auto tmp = s.lower_bound(sum-K);
            if(tmp != s.end()) result = max(result, sum- *tmp);
            s.insert(sum);
        }
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        K=k, m=matrix.size(), n=matrix[0].size();
        if(n > m){   
            vector<int> rowSum(n);   
            for(int i=0; i<m; i++){
                fill(rowSum.begin(), rowSum.end(), 0);
                for(int row=i; row<m; row++){    
                    for(int col=0; col<n; col++){
                        rowSum[col] += matrix[row][col];
                    }
                    updateResult(rowSum);
                }
            }
            if(result == k)return result;
        }
        else{ 
            vector<int> colSum(m);
            for(int i=0; i<n; i++){
                fill(colSum.begin(), colSum.end(), 0);
                for(int col=i; col<n; col++){
                    for(int row=0; row < m; row++)
                        colSum[row] += matrix[row][col];
                    updateResult(colSum);
                }
            }
        }
        return result;
    }
};