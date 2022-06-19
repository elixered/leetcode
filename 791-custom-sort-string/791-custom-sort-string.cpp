class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26,0);
        for(auto c:s)
            count[c-'a']++;
        string ans;
        for(auto c:order){
            if(count[c-'a']){
                ans += string(count[c-'a'],c);
                count[c-'a'] = 0;
            }
        }
        for(int i=0; i<26; i++){
            if(count[i]){
                ans += string(count[i],(i+'a'));
            }
        }
        return ans;
    }
};