class Solution {
public:
    
    string recur(string& s, int& idx){
        string ans;
        while(idx < s.size()){
            while(idx < s.size() && isalpha(s[idx]))
                ans += s[idx++];
            int curr = 0;
            while(idx < s.size() && isdigit(s[idx]))
                curr = curr*10 + s[idx++]-'0';
            if(s[idx]==']')
                return ans;
            ++idx;
            string t = recur(s,idx);
            ++idx;
            while(curr-- > 0)
                ans += t;
        }
        return ans;
    }
    
    string decodeString(string s) {
        int idx = 0;
        return recur(s,idx);
    }
};