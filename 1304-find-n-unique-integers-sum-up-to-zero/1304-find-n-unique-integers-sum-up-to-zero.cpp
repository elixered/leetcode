class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int curr = 1;
        for(int i=1; i<=n/2; ++i){
            ans.push_back(-curr);
            ans.push_back(curr++);
        }
        if(n%2){
            ans.push_back(0);
        }
        return ans;
    }
};