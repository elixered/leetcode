class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> zero(n,0),one(n,0);
        if(s[0]=='0') zero[0]++;
        else one[0]++;
        for(int i=1; i<n; i++)
        {
            zero[i] = zero[i-1];
            one[i] = one[i-1];
            s[i]=='0'?zero[i]++:one[i]++;
        }
        int ans = n;
        for(int i=0; i<n; i++)
        {
            int prevone = one[i];
            int nextzero = zero[n-1]-zero[i];
            ans = min(ans,prevone+nextzero);
        }
        return min(ans,zero[n-1]);
    }
};