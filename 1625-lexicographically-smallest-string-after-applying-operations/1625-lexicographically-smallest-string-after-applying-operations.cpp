class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        int n = s.size();
        queue<string> q;
        q.push(s);
        unordered_set<string> st;
        st.insert(s);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans = min(ans,curr);
            string x = curr.substr(n-b,b) + curr.substr(0,n-b);
            string y  = curr;
            for(int i=0; i<curr.size(); ++i){
                if(i%2)
                    y[i] = '0' + (curr[i]-'0'+a)%10;
            }
            if(st.count(y) == 0){
                st.insert(y);
                q.push(y);
            }
            if(st.count(x) == 0){
                st.insert(x);
                q.push(x);
            }
        }
        return ans;
    }
};