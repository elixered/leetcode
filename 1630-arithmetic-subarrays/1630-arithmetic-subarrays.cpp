class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = r.size();
        vector<bool> ans(m,0);
        for(int i=0; i<m; i++)
        {
            if(r[i]-l[i]+1<2)
            {
                ans[i] = false;
                continue;
            }
            vector<int> temp;
            for(int j=l[i]; j<=r[i]; j++)
            {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            int diff = temp[1]-temp[0];
            bool flag = true;
            for(int i=1; i<temp.size(); i++)
            {
                if(temp[i]-temp[i-1]!=diff)
                {
                    flag = false;
                    break;
                }
            }
            ans[i] =  flag;
        }
        return ans;
    }
};