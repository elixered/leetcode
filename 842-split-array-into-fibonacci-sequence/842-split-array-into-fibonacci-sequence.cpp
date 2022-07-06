class Solution {
public:
    vector<int> ans;
    
    void solve(string& s, vector<int>& temp, int idx){
        if(idx == s.size()){
            if(temp.size()>=3)
            ans = temp;
            return;
        }
        int n = s.size();
        if(temp.size()<2){
            long curr = 0;
            for(int i=idx; i<n; ++i){
                if(i>idx && s[idx]=='0') break;
                curr = curr*10 + s[i]-'0';
                if(curr>INT_MAX)
                    break;
                temp.push_back(curr);
                solve(s,temp,i+1);
                temp.pop_back();
            }
        }
        else{
            long prev = temp.back();
            prev += temp[temp.size()-2];
            long curr = 0;
            for(int i=idx; i<n; ++i){
                if(i>idx && s[idx]=='0') break;
                curr = curr*10 + s[i]-'0';
                if(curr>INT_MAX)
                    break;
                if(curr == prev){
                    temp.push_back(curr);
                    solve(s,temp,i+1);
                    temp.pop_back();
                }
            }
        }
    }
    
    vector<int> splitIntoFibonacci(string s) {
        vector<int> temp;
        solve(s,temp,0);
        return ans;
    }
};