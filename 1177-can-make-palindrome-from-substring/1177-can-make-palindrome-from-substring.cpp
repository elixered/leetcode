class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> count(n,vector<int>(26,0));
        count[0][s[0]-'a']++;
        for(int i=1; i<n; i++){
            for(int j=0; j<26; j++){
                count[i][j] = count[i-1][j];
            }
            count[i][s[i]-'a']++;
        }
        vector<bool> ans;
        for(auto q:queries){
            int left = q[0];
            int right = q[1];
            int c = 0;
            for(int i=0; i<26; i++){
                int total = count[right][i];
                if(left>0)
                    total -= count[left-1][i];
                if(total%2)
                    c++;
            }
            bool res = c/2 <= q[2];
            ans.push_back(res);
        }
        return ans;
    }
};