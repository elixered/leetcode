class Solution {
public:
     unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n!=s2.size()) return false;
        if(s1==s2) return true;
        bool flag = false;
        string key = s1+" "+s2;
        if(mp.find(key)!=mp.end())
            return mp[key];
        for(int i=1; i<n; i++){
            string x1 = s1.substr(0,i);
            string y1 = s1.substr(i);
            string x2 = s2.substr(0,i);
            string y2 = s2.substr(i);
            string y3 = s2.substr(0,n-i);
            string x3 = s2.substr(n-i);
            flag = flag || (isScramble(x1,x2) && isScramble(y1,y2));
            flag = flag || (isScramble(x1,x3) && isScramble(y1,y3));
        }
        return mp[key] =  flag;
    }
};