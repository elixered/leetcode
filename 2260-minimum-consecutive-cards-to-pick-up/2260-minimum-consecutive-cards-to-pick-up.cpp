class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int n = cards.size();
        int ans = n+1;
        for(int i=0; i<n; i++){
            if(mp.find(cards[i])!=mp.end())
                ans = min(ans,i-mp[cards[i]]+1);
            mp[cards[i]] = i;
        }
        return ans>n?-1:ans;
    }
};