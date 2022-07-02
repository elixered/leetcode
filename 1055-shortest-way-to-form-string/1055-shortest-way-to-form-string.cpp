class Solution {
public:
    
    vector<vector<int>> dp;    
    int move(string& source, string& target, int i){
        int j = 0;
        int n = source.size();
        int m = target.size();
        while(i<m && j<n){
            int curr = target[i] - 'a';
            int nextIdx = dp[j][curr];
            if(nextIdx == -1) return i;
            else{
                i++;
                j = nextIdx+1;
            }
        }
        return i;
    }
    
    int shortestWay(string source, string target) {
        int i = 0;
        int n = target.size();
        int s = 0;
        dp = vector<vector<int>>(source.size(),vector<int>(26,-1));
        int m = source.size();
        dp[m-1][source.back()-'a'] = m-1;
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<26; ++j){
                dp[i][j] = dp[i+1][j];
            }
            dp[i][source[i]-'a'] = i;
        }
        while(i<n){
            int j = move(source,target,i);
            if(i==j) return -1;
            i = j;
            s++;
        }
        return s;
    }
};