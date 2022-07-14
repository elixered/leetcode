class Solution {
public:
    int ans = INT_MAX;
    
    
    void getAns(vector<int>& v){
        for(auto i:v)
            if(i == 0)
                return;
        int curr = 0;
        for(auto i:v){
            curr = max(curr,i);
        }
        ans = min(ans,curr);
    }
    
    void solve(vector<int>& cookies, int idx, int k,vector<int>& v){
        if(idx == cookies.size()){
            getAns(v);
            return;
        }
        for(int i=0; i<k; ++i){
            v[i] += cookies[idx];
            solve(cookies,idx+1,k,v);
            v[i] -= cookies[idx];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> v;
        v.resize(k,0);
        solve(cookies,0,k,v);
        return ans;
    }
};