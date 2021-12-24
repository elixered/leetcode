class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int inf = pow(10,7);
        int distance[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    distance[i][j] = 0;
                else distance[i][j] = inf;
            }
        }
        for(auto it:edges)
        {
            distance[it[0]][it[1]] = it[2];
            distance[it[1]][it[0]] = it[2];
        }
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
                }
            }
        }
        int count = n+1;
        int city = 0;
        for(int i=0; i<n; i++)
        {
            int temp = 0;
            for(int j=0; j<n; j++)
            {
                if(i==j) continue;
                if(distance[i][j]<=distanceThreshold && distance[i][j]!=inf)
                    temp++;
            }
            if(temp<=count)
            {
                city = i;
                count = temp;
            }
        }
        return city;
    }
};