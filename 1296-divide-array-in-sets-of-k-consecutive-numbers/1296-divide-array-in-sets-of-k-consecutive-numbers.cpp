class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;
        multiset<int> set(nums.begin(),nums.end());
        while(!set.empty())
        {
            auto curr = *set.begin()-1;
            for(int i=0; i<k; i++)
            {
                auto it = set.find(curr+1);
                if(it==set.end()) return false;
                set.erase(it);
                curr++;
            }
        }
        return true;
    }
};