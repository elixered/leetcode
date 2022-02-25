class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size();
        long long sum = 0;
        int neg = 0;
        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(a[i][j]<0)
                    neg++;
                sum += abs(a[i][j]);
                mini = min(mini,abs(a[i][j]));
            }
        }
        if(neg%2==0)
            return sum;
        else return sum - 2*mini;
    }
};