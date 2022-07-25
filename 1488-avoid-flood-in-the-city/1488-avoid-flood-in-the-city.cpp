class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_set<int> st;
        int n = rains.size();
        unordered_map<int,int> mp;
        vector<int> ans(n,-1);
        set<int> eraser;
        for(int i=0; i<n; ++i){
            if(rains[i]){
                if(mp.count(rains[i])){
                    auto itr = eraser.lower_bound(mp[rains[i]]);
                    if(itr == eraser.end())
                        return {};
                    ans[*itr] = rains[i];
                    eraser.erase(itr);
                }
                mp[rains[i]] = i;
            }
            else{
                eraser.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};