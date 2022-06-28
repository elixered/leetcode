class Solution {
public:
    
    int goal;
    
    void solve(const string& nums, string s, int idx, long curval, long last, vector<string>& ans){
        if(idx >= nums.size()){
            if(curval == goal)
                ans.push_back(s);
            return;
        }
        long num = 0;
        string numstr;
        for(int i=idx; i<nums.size(); ++i){
            if(i>idx && nums[idx]=='0') return;
            numstr += nums[i];
            num = num*10 + (nums[i]-'0');
            if(idx==0)
                solve(nums,to_string(num),i+1,num,num,ans);
            else{
                solve(nums,s+"+"+numstr,i+1,curval+num,num,ans);
                solve(nums,s+"-"+numstr,i+1,curval-num,-num,ans);
                solve(nums,s+"*"+numstr,i+1,curval-last+last*num,last*num,ans);
            }
        }
    }
    
    vector<string> addOperators(string& num, int target) {
        vector<string> ans;
        goal = target;
        solve(num,"",0,0,0,ans);
        return ans;
    }
};