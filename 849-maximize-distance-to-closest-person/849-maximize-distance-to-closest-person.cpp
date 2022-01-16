class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> left(n),right(n);
        int prev = -n;
        for(int i=0; i<n; i++)
        {
            if(seats[i]==1)
                prev = i;

            left[i] = i-prev;
        }
        prev = 2*n;
        for(int i=n-1; i>=0; i--)
        {
            if(seats[i]==1)
                prev = i;
            else right[i] = prev-i;
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans = max(ans,min(left[i],right[i]));
        }
        return ans;
    }
};