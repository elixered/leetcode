class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for(int i=0; i<n; i++)
        {
            int j=i;
            string s = to_string(nums[i]);
            while(j<n-1 && nums[j]+1==nums[j+1])
            {
                j++;
            }
            if(j!=i)
            s += "->"+to_string(nums[j]);
            ans.push_back(s);
            i = j;
        }
        return ans;
    }
};