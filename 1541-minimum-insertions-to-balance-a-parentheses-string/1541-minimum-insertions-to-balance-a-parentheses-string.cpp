class Solution {
public:
    int minInsertions(string s) {
        int curr = 0;
        int ans = 0;
        for(int i=0; i<s.size(); ++i){
            curr += s[i]==')' ? -1 : 2;
            if(curr < 0){
                curr += 2;
                ans++;
            }
            else if(s[i] == '(' && curr % 2 != 0){
                ans++;
                curr--;
            }
        }
        return ans + curr;
    }
};