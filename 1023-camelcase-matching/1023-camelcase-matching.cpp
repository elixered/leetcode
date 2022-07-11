class Solution {
public:
    
    bool solve(string s, string pat){
        int m = s.size();
        int n = pat.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(isupper(s[i])){
                if(s[i] == pat[j]){
                    i++;
                    j++;
                }
                else return false;
            }
            else{
                if(s[i] == pat[j])
                    j++;
                i++;
            }
        }
        if(j<n) return false;
        while(i<m){
            if(isupper(s[i++]))
                return false;
        }
        return true;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto s:queries){
            ans.push_back(solve(s,pattern));
        }
        return ans;
    }
};