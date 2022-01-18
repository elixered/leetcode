class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int sz = s.size();
        bool f = next_permutation(s.begin(),s.end());
        if(f==false) return -1;
        long long x = stoll(s);
        if(x>INT_MAX)
            return -1;
        return (int)x;
    }
};