class Solution {
public:
int dfs(vector<string>& ws, vector<int> &cnt, vector<int> &score, int i) {
    if (i >= ws.size()) return 0;
    auto skipGain = dfs(ws, cnt, score, i + 1), gain = 0, formed = 1;
    vector<int> cnt1(begin(cnt), end(cnt));
    for (auto ch : ws[i]) {
        if (--cnt1[ch - 'a'] < 0) formed = 0;
        gain += score[ch - 'a'];
    }
    return max(skipGain, formed ? 
        gain + dfs(ws, cnt1, score, i + 1) : 0);
}
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<int> cnt(26);
    for (auto ch : letters) ++cnt[ch - 'a'];
    return dfs(words, cnt, score, 0);
}
};