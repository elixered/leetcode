class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        int prev = -1;
        int next = -1;
        vector<int> ans(n,0);
        for(int i=0; i<n; i++)
        {
            if(s[i]==c)
                prev = i;
            if(next<i)
            {
                next=i;
                while(next<n && s[next]!=c)
                    next++;
            }
            int left = (prev==-1 ? INT_MAX:i-prev);
            int right = (next==n ? INT_MAX:next-i);
            ans[i] = min(left,right);
        }
        return ans;
    }
};