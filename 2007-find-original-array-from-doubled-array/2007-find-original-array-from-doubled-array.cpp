class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        unordered_multiset<int> set(changed.begin(),changed.end()),deleted;
        vector<int> ans;
        int n = changed.size();
        if(n%2!=0) return {};
        int mid = n/2;
        int i = n-1;
        while(mid>0)
        {
            if(deleted.find(changed[i])!=deleted.end())
            {
                deleted.erase(deleted.find(changed[i]));
                i--;
                continue;
            }
            if(changed[i]%2!=0 or set.find(changed[i]/2)==set.end() or set.find(changed[i])==set.end())
                return {};
            else
            {
                ans.push_back(changed[i]/2);
                set.erase(set.find(changed[i]));
                set.erase(set.find(changed[i]/2));
                deleted.insert(changed[i]/2);
                i--;
                mid--;
            }
        }
        return ans;
    }
};