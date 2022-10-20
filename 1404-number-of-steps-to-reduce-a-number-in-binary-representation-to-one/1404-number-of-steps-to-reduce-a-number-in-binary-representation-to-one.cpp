class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int found = 0;
        for(int i=s.size()-1; i > 0; --i){
            if(!found){
                if(s[i] == '0')
                    ans++;
                else{
                    found = 1;
                    ans += 2;
                }
            }
            else{
                if(s[i] == '0'){
                    ans += 2;
                }
                else
                    ans++;
            }
        }
        return ans + found;
    }
};