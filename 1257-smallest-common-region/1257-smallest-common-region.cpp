class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string,string> mp;
        for(auto region:regions){
            for(int i=1; i<region.size(); ++i)
                mp[region[i]] = region[0];
        }
        unordered_set<string> st;
        while(mp.find(region1) != mp.end()){
            st.insert(region1);
            region1 = mp[region1];
        }
        while(mp.find(region2) != mp.end()){
            if(st.find(region2) != st.end())
                return region2;
            region2 = mp[region2];
        }
        return region2;
    }
};