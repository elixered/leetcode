class Solution {
public:
    static bool cmp(int a, int b)
    {
        string x = to_string(a);
        string y = to_string(b);
        
        return (x+y)>(y+x)?true:false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans = "";
        for(auto& it:nums)
            ans += to_string(it);
        string res = "";
        int i=0;
        while(i<ans.size() && ans[i]=='0')
            i++;
        if(i==ans.size()) return "0";
        return ans;
    }
};