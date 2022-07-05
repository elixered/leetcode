class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(26,0);
        for(int i=0; i<order.size(); ++i)
            mp[order[i]-'a'] = i;
        for(int i=1; i<words.size(); ++i){
            string& curr = words[i];
            string& prev = words[i-1];
            bool flag = false;
            for(int i=0; i<min(curr.size(),prev.size()); ++i){
                if(mp[curr[i]-'a'] < mp[prev[i]-'a'])
                    return false;
                else if(prev[i]!=curr[i]){
                    flag = true;
                    break;
                }
            }
            if(flag == false && prev.size() > curr.size()) return false;
        }
        return true;
    }
};