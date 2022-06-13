class Solution {
public:
    #define ll long long
    
    ll count(vector<int>& candies, ll mini)
    {
        ll ans = 0;
        for(auto& it:candies)
        {
            ans += (it)/mini;
        }
        return ans;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        ll low = 1, high = pow(10,12);
        ll ans = 0;
        while(low <= high)
        {
            ll mid = low + (high-low)/2;
            if(count(candies,mid) >= k)
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};