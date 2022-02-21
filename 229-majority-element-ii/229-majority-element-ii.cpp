class Solution {
public:
    bool check(vector<int>& nums, int x)
    {
        int n = nums.size();
        int c = 0;
        for(auto it:nums)
            if(it==x)
                c++;
        return c > n/3;
    }
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        int a = INT_MAX,c1=0,b=INT_MAX,c2=0;
        for(int i=0; i<n; i++)
        {
            int curr = nums[i];
            if(curr == a)
                c1++;
            else
            if(curr == b)
                c2++;
            else
            if(c1==0)
            {
                a = curr;
                c1 = 1;
            }
            else if(c2==0)
            {
                b = curr;
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        if(check(nums,a)) ans.push_back(a);
        if(check(nums,b)) ans.push_back(b);
        return ans;
    }
};