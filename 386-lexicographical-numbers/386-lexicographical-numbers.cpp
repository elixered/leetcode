class Solution {
public:
    vector<int> ans;
    
    void solve(int curr, int n){
        if(curr > n or ans.size() == n)
            return;
        ans.push_back(curr);
        solve(curr*10,n);
        if(curr%10 != 9)
            solve(curr+1,n);
    }
    
    vector<int> lexicalOrder(int n) {
        solve(1,n);
        return ans;
    }
};