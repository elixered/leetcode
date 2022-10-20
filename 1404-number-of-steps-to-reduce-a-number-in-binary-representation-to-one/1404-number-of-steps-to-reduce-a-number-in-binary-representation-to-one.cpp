class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=n-1; i>0; --i){
            if(s[i] == '0')
                ans++;
            else{
                int j = i-1;
                while(j >= 0){
                    if(s[j] == '0'){
                        s[j] = '1';
                        break;
                    }
                    else
                        s[j] = '0';
                    j--;
                }
                ans += 2;
            }
        }
        if(s[0] == '0')
            return ans+1;
        else
            return ans;
    }
};