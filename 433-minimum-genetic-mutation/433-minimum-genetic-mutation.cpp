class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        string s = "AGCT";
        unordered_set<string> st(begin(bank),bank.end()), visited;
        int steps = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto f = q.front();
                q.pop();
                if(f == end)
                    return steps;
                if(visited.find(f) == visited.end()){
                    visited.insert(f);
                    for(int i=0; i<8; ++i){
                        char curr = f[i];
                        for(int j=0; j<4; ++j){
                            f[i] = s[j];
                            if(st.find(f) != st.end())
                                q.push(f);
                        }
                        f[i] = curr;
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};