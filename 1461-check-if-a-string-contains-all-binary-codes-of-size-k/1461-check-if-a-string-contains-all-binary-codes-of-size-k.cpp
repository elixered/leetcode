class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(k==0 or k>n) return 0;
        int maxi = (1<<(k))-1;
        int mini = 0;
        int curr = 0;
        int prod = 1;
        set<int> st;
        for(int i=k-1; i>=0; i--)
        {
            curr += prod*(s[i]-'0');
            prod*=2;
        }
        prod /= 2;
        st.insert(curr);
        for(int i=k; i<n; i++)
        {
            curr -= prod*(s[i-k]-'0');
            curr *= 2;
            curr += s[i]-'0';
            st.insert(curr);
        }
        return st.size()==maxi-mini+1;
    }
};