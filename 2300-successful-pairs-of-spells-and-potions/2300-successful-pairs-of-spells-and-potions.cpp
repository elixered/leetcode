class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(begin(potions),end(potions));
        vector<int> ans(n,0);
        for(int i=0; i<n; i++)
        {
            long long curr = spells[i];
            long long req = (success+curr-1)/curr;
            auto it = lower_bound(begin(potions),end(potions),req)-potions.begin();
            ans[i] = m-it;
        }
        return ans;
    }
};