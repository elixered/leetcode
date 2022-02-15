class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> nums = {a,b,c};
        sort(nums.begin(),nums.end());
        a = nums[0];
        b = nums[1];
        c = nums[2];
        if(a+b<=c)
            return a+b;
        else
        {
            int ans = 0;
            ans += (a+b-c)/2+c;
            return ans;
        }
        return a;
    }
};