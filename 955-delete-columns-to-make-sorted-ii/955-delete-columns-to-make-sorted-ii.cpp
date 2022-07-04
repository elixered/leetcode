class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int ans = 0;
        vector<int> sorted(m,0);
        for(int i=0; i<n; ++i){
            int temp = ans;
            for(int j=1; j<m; ++j){
                if(!sorted[j-1] && strs[j][i] < strs[j-1][i]){
                    ans++;
                    break;
                }
            }
            if(ans == temp){
                for(int j=1; j<m; ++j){
                    sorted[j-1] = sorted[j-1] || strs[j-1][i] < strs[j][i];
                }
            }
        }
        return ans;
    }
};