class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        int n = s.size();
        while(i<n)
        {
            reverse(s.begin()+i,i+k>n?s.end():s.begin()+i+k);
            i += 2*k;
        }
        return s;
    }
};