class Solution {
public:
    unordered_map<int,unordered_map<string,int>> mp;
    int solve(vector<string>& words, int idx, multiset<char> st, vector<int>& score){
        if(idx == words.size()){
            return 0;
        }
        string s;
        for(auto it:st)
            s.push_back(it);
        if(mp[idx].count(s)) return mp[idx][s];
        int mx = 0;
        auto word =  words[idx];
        auto stc = st;
        int val = 0;
        for(auto c:word){
            if(st.find(c) != st.end()){
                st.erase(st.find(c));
                val += score[c-'a'];
            }
            else{
                return solve(words,idx+1,stc,score);
            }
        }
        mx = max(solve(words,idx+1,st,score)+val,solve(words,idx+1,stc,score));
        return mp[idx][s] = mx;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        multiset<char> st(begin(letters),end(letters));
        return solve(words,0,st,score);
    }
};