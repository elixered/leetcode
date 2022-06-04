class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int maximum = nums[0];
        vector<int> minimum = nums;
        for(int i=n-2; i>=0; i--)
            minimum[i] = min(minimum[i+1],nums[i]);
        for(int i=1; i<n; i++)
        {
            if(maximum <= minimum[i])
                return i;
            else maximum = max(maximum,nums[i]);
        }
        return n;
    }
};