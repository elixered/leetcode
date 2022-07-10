class Solution {
public:
    int ans = INT_MAX;
    int diff = INT_MAX;
    
    void solve(vector<int>& t, int idx, int target, int cost){
        if(abs(cost-target) <= diff){
            if(abs(cost-target) == diff)
                ans = min(ans,cost);
            else ans = cost;
            diff = abs(cost-target);
        }
        if(idx == t.size() or cost-target > diff)
            return;
        solve(t,idx+1,target,cost);
        solve(t,idx+1,target,cost + t[idx]);
        solve(t,idx+1,target,cost + 2*t[idx]);
    }
    
    int closestCost(vector<int>& b, vector<int>& t, int target) {
        for(auto it:b){
            solve(t,0,target,it);
        }
        return ans;
    }
};