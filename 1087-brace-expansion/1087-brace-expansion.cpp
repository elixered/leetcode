class Solution {
public:
    vector<string> ans;
    void add(queue<string>& q, string curr){
        int n = q.size();
        while(n-- > 0){
            auto f = q.front();
            q.pop();
            for(auto c:curr){
                f.push_back(c);
                q.push(f);
                f.pop_back();
            }
        }
    }
    vector<string> expand(string s) {
        queue<string> q;
        q.push("");
        int i = 0;
        int n = s.size();
        while(i<n){
            if(s[i]=='{'){
                int j = i+1;
                string curr;
                while(j<n && s[j]!='}'){
                    if(s[j]==','){
                        j++;
                        continue;
                    }
                    curr += s[j++];
                }
                add(q,curr);
                i = j+1;
            }
            else add(q,string(1,s[i++]));
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};