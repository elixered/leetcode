class Solution {
public:
    static bool cmp(vector<int>& n1, vector<int>& n2)
    {
        if(n1[0]==n2[0])
            return n1[1]>n2[1];
        else return n1[0]<n2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int n = nums.size();
        if(n<=1) return n;
        int l = nums[0][0];
        int r = nums[0][1];
        int c = 0;
        for(int i=1; i<n; i++)
        {
            int a = nums[i][0];
            int b = nums[i][1];
            if(a>=l && b<=r)
                c++;
            else
            {
                l = a;
                r = b;
            }
        }
        return n-c;
    }
};