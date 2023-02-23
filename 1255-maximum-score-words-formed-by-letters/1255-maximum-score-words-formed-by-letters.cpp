class Solution {
public:
    int mx = 0;
    
    void solve(vector<string>& words, int idx, multiset<char> st, vector<int>& score, int curr){
        if(idx == words.size()){
            mx = max(mx,curr);
            return;
        }
        auto word =  words[idx];
        auto stc = st;
        int val = 0;
        for(auto c:word){
            if(st.find(c) != st.end()){
                st.erase(st.find(c));
                val += score[c-'a'];
            }
            else{
                solve(words,idx+1,stc,score,curr);
                return;
            }
        }
        solve(words,idx+1,stc,score,curr);
        solve(words,idx+1,st,score,curr+val);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        multiset<char> st(begin(letters),end(letters));
        solve(words,0,st,score,0);
        return mx;
    }
};