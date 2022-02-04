class Solution {
public:
    static bool cmp(int a, int b)
    {
        string x = to_string(a);
        string y = to_string(b);
        int m = min(x.size(),y.size());
        for(int i=0; i<m; i++)
        {
            if(x[i]>y[i]) return true;
            else if(x[i]<y[i]) return false;
        }
        if(x.size()>y.size())
        {
            for(int i=m; i<x.size(); i++)
            {
                if(x[i]>y[i%m]) return true;
            else if(x[i]<y[i%m]) return false;
            }
        }
        else if(x.size()<y.size())
        {
            for(int i=m; i<y.size(); i++)
            {
                if(x[i%m]>y[i]) return true;
            else if(x[i%m]<y[i]) return false;
            }
        }
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