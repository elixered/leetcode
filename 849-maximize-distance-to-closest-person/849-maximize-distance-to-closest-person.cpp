class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> left(n),right(n);
        int prev = -n;
        int next=0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(seats[i]==1)
                prev = i;
            else
            {
                while((next<n && seats[next]==0) or next<i)
                    next++;
            }
            if(next>=n)
                next = 2*n;
            ans = max(ans,min(next-i,i-prev));
        }
        
        return ans;
    }
};