class Solution {
public:
    bool canReorderDoubled(vector<int>& changed) {
        multiset<int> set(changed.begin(),changed.end());
        int n = changed.size();
        if(n%2!=0) return {};
        while(set.size())
        {
            auto it = set.begin();
            int y;
            if(*it<0)
            {
                if(*it%2!=0) return false;
                else y = *it/2;
            }
            else y = 2*(*it);
            set.erase(it);
            if(set.find(y)==set.end())
                return false;
            else
            {
                set.erase(set.find(y));
            }
        }
       return set.size()==0;
    }
};