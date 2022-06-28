class Solution {
public:
    
    unordered_map<int,int> mp;
    unordered_map<int,unordered_map<int,bool>> dp;
    int solve(vector<int>& stones, int idx, int maxjump){
        if(idx == stones.size()-1) return true;
        if(dp[idx].find(maxjump)!=dp[idx].end()) return dp[idx][maxjump];
        for(int jump=maxjump-1; jump<=maxjump+1; jump++){
            if(jump<=0) continue;
            if(mp.find(stones[idx]+jump)!=mp.end())
                if(solve(stones,mp[stones[idx]+jump],jump))
                    return dp[idx][maxjump] = true;
        }
        return dp[idx][maxjump] = false;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        for(int i=0; i<stones.size(); ++i)
            mp[stones[i]] = i;
        return solve(stones,1,1);
    }
};