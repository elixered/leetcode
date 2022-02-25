class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size();
        bool flag = false;
        long long sum = 0;
        int mini = INT_MAX;
        int tneg = 0;
        for(int i=0; i<n; i++)
        {
            int neg = 0;
            for(int j=0; j<n; j++)
            {
                if(a[i][j]<0)
                    neg++;
                sum += abs(a[i][j]);
                mini = min(mini,abs(a[i][j]));
            }
            if(neg%2!=0)
            {
                flag = true;
                tneg++;
            }
        }
        if(flag = false or tneg%2==0)
            return sum;
        else return sum - 2*mini;
    }
};