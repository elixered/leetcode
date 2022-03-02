class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map1,map2;
        for(int i=0; i<list1.size(); i++)
            map1[list1[i]] = i;
        for(int i=0; i<list2.size(); i++)
            map2[list2[i]] = i;
        int ans = 200000;
        for(auto it:map1)
        {
            if(map2.find(it.first)!=map2.end())
                ans = min(ans,it.second+map2[it.first]);
        }
        vector<string> res;
        for(auto it:map1)
        {
            if(map2.find(it.first)!=map2.end())
                if(it.second+map2[it.first]==ans)
                    res.push_back(it.first);
        }
        return res;
    }
};