class Solution { // 4 ms, faster than 99.32%
public:
    vector<vector<string>> findLadders(const string& beginWord, const string& endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // to check if a word is existed in the wordSet, in O(1)
        wordSet.erase(beginWord);

        unordered_map<string, vector<vector<string>>> level;
        level[beginWord] = {{beginWord}}; // level[word] is all possible sequence paths which start from beginWord and end at `word`.
        while (!level.empty()) {
            unordered_map<string, vector<vector<string>>> newLevel;
            for (const auto& [word, paths] : level) {
                if (word == endWord)
                    return level[word]; // return all shortest sequence paths
                for (const string& nei : neighbors(word, wordSet)) {
                    for (auto path : paths) {
                        path.push_back(nei); // form new paths with `nei` word at the end
                        newLevel[nei].push_back(path);
                    }
                }
            }
            for (const auto& [word, _] : newLevel) wordSet.erase(word); // remove visited words to prevent loops
            level.swap(newLevel); // move to new level
        }
        return {};
    }
    vector<string> neighbors(const string& word, const unordered_set<string>& wordSet) {
        vector<string> ans;
        for (int i = 0; i < word.size(); ++i) { // change every possible single letters and check if it's in wordSet
            for (char c = 'a'; c <= 'z'; ++c) {
                string newWord = word.substr(0, i) + c + word.substr(i+1);
                if (!wordSet.count(newWord)) continue;
                ans.push_back(newWord);
            }
        }
        return ans;
    }
};