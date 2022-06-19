class Solution {
public:
    vector<string> ans;
    void solve(string& s, int idx, string curr,int parts){
        if(parts > 4) return;
        if(idx==s.size()){
            if(parts==4)
            ans.push_back(curr);
            return;
        }
        int n = s.size();
        string temp;
        for(int i=idx; i<min(n,idx+3); i++){
            if(temp=="0") return;
            temp += s[i];
            if(stoi(temp)<=255){
                string t;
                if(curr.size()==0)
                    t += temp;
                else t = curr+"."+temp;
                solve(s,i+1,t,parts+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return ans;
        solve(s,0,"",0);
        return ans;
    }
};