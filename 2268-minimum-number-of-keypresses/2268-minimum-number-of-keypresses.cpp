class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> m(26);
        for(char ch : s) {
            m[ch - 'a']++; 
        }
        sort(m.begin(),m.end());
        int c = 0; 
        int ret = 0; 
        for(int i = m.size()-1;i>=0;i--) { 
            ret += (c / 9 +1) * m[i];
            c++; 
        }
        return ret; 
    }
};