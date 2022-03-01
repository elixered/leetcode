class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int poisoned = -1;
        sort(timeSeries.begin(),timeSeries.end());
        for(auto it:timeSeries)
        {
            ans += duration;
            if(poisoned >= it)
                ans -= (min(poisoned,it+duration-1)-it+1);
            poisoned = it+duration-1;
        }
        return ans;
    }
};