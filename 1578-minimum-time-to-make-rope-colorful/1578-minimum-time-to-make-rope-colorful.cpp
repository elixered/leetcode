class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.size();
        int ans = 0;
        for(int i=0; i<n; )
        {
            int j = i+1;
            int sum = time[i];
            int mx = time[i];
            while(j < n && colors[i] == colors[j])
            {
                sum += time[j];
                mx = max(mx,time[j]);
                j++;
            }
            ans += sum - mx;
            i = j;
        }
        return ans;
    }
};