class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size(),i;
        bitset<26> dp[n];
        
       dp[0][s[0]-'a']=1;
        //cout<<dp[0]<<"\n";
        for(i=1;i<n;i++)
        {
           // cout<<(1<<(s[i]-'a'))<<"\n";
            dp[i]=dp[i-1];
            dp[i]^=(1<<(s[i]-'a'));//toggle
                //cout<<dp[i]<<" bit\n";
        }
        vector<bool> ans;
        for(auto &q:queries)
        {
            int end=q[1],st=q[0],k=q[2];
            bitset<26> res=st==0?dp[end]:dp[end]^dp[st-1];
            //cout<<res.count()<<"\n";
            ans.push_back(res.count()/2<=k?true:false);
        }
        return ans;
    }
};