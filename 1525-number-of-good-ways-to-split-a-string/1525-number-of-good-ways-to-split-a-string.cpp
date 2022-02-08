class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> left(n),right(n);
        unordered_set<char> lset,rset;
        for(int i=0; i<n; i++)
        {
            lset.insert(s[i]);
            left[i] = lset.size();
            rset.insert(s[n-1-i]);
            right[n-1-i] = rset.size();
        }
        int count = 0;
        for(int i=0; i<n-1; i++)
            if(left[i]==right[i+1])
                count++;
        return count;
    }
};