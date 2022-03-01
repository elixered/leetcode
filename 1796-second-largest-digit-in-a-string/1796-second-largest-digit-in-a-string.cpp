class Solution {
public:
    int secondHighest(string s) {
        vector<int> ans(10,0);
        for(auto c:s)
        {
            if(c>='0' && c<='9')
                ans[c-'0']++;
        }
        int max1 = -1,max2 = -1;
        for(int i=9; i>=0; i--)
        {
            if(ans[i]==0) continue;
            else if(max1==-1)
                max1 = i;
            else return i;
        }
        return -1;
    }
};