class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> map;
        if(nums.size()%k !=0) return false;
        for(auto it:nums)
            map[it]++;
        for(int j=0; j<nums.size()/k; j++)
        {
            for(auto it:map)
            {
                if(it.second>0)
                {
                    for(int i=0; i<k; i++)
                    {
                        if(map[it.first+i]<=0) return false;
                        else map[it.first+i]--;
                    }
                    break;
                }
            }
        }
        return true;
    }
};