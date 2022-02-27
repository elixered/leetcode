class Solution {
public:
    #define ll long long
    ll M = pow(10,6);
    int minimumFinishTime(vector<vector<int>>& tires, int change, int laps) {
        vector<ll> best(max(laps+1,21),INT_MAX);
        best[0] = 0;
        for(auto& t:tires)
        {
            ll curr = t[0];
            ll last = 0;
            for(int d=1; d<=20; d++)
            {
                best[d] = min(best[d], last+curr);
                last += curr;
                curr *= t[1];
                if(curr>M) break;
            }
        }
        for(ll d=1; d<=laps; d++)
        {
            for(ll l = min(d,(ll)20); l>=1; l--)
            {
                best[d] = min(best[d], best[l]+best[d-l]+change);
            }
        }
        return best[laps];
    }
};