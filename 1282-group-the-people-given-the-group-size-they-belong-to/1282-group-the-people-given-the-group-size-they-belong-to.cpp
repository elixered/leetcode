class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        for(int i=0; i<g.size(); i++)
        {
            mp[g[i]].push_back(i);
        }
        for(auto it:mp)
        {
            int gs = it.first;
            while(!it.second.empty())
            {
                vector<int> temp;
                for(int i=0; i<gs; i++)
                {
                    temp.push_back(it.second.back());
                    it.second.pop_back();
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};