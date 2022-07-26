class Solution {
public:
    string removeDigit(string s, char digit) {
        int removeIdx = s.find(digit);
        for(int i=removeIdx; i<s.size(); ++i){
            if(s[i] == digit){
                if(i+1 < s.size() && s[i+1] > s[i])
                    return s.substr(0,i) + s.substr(i+1);
                else removeIdx = i;
            }
        }
        return s.substr(0,removeIdx) + s.substr(removeIdx+1);
    }
};