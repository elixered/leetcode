class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> diff(32,vector<int>(2,0));
        for(int i=0; i<32; i++)
        {
            for(auto it:nums)
            {
                if((it&(1<<i))!=0)
                    diff[i][1]++;
                else diff[i][0]++;
            }
        }
        int ans = 0;
        for(auto it:diff)
            ans += it[0]*it[1];
        return ans;
    }
};