class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        int k = nums.size();
        int as,ae=  INT_MIN,cs = INT_MAX,ce;
        for(int i=0; i<k; ++i){
            for(auto it:nums[i]){
                cs = min(cs,it);
                ae = max(ae,it);
                mp[it].push_back(i);
            }
        }
        ce = cs;
        as = cs;
        unordered_map<int,int> hm;
        auto s = mp.begin();
        auto e = mp.begin();
        while(e != mp.end()){
            for(auto it:e->second)
                hm[it]++;
            while(hm.size() == k && s != e){
                if(e->first - s->first < ae - as){
                    ae = e->first;
                    as = s->first;
                }
                for(auto it:s->second){
                    hm[it]--;
                    if(hm[it] == 0)
                        hm.erase(it);
                }
                s++;
            }
            if(hm.size() == k && s == e)
                return {s->first,s->first};
            e++;
        }
        return {as,ae};
    }
};