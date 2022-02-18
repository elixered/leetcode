class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> set(changed.begin(),changed.end());
        int n = changed.size();
        if(n%2!=0) return {};
        vector<int> ans;
        while(set.size())
        {
            auto it = set.begin();
            int y = 2*(*it);
            set.erase(it);
            if(set.find(y)==set.end())
                return {};
            else
            {
                ans.push_back(y/2);
                set.erase(set.find(y));
            }
        }
        if(ans.size()==0) return {};
        return ans;
    }
};