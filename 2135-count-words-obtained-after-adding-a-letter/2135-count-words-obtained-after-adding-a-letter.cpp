class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        std::unordered_map<int, std::unordered_set<std::string>> words;
        // O(M) operation where M is the number of start words.
        for(auto& word: startWords) {
            // Constant time operation since it is guaranteed that there are at max 26 chars
            std::sort(word.begin(), word.end());
            // 2*O(1) = O(1) operation
            words[word.size()].insert(word);
        }
        
        size_t count = 0;
        // O(N) operation where N is the number of target words.
        for(auto& word: targetWords) {
            // Constant time operation since it is guaranteed that there are at max 26 chars
            std::sort(word.begin(), word.end());
            // O(26) max operation
            for(int i = 0; i < word.size(); i++) {
                const std::string to_search = word.substr(0, i) + word.substr(i+1);
                // O(1) operation
                auto it = words.find(to_search.size());
                
                if (it != words.end()) {
                    auto const& words_set = it->second;
                    // O(1) although calculating the hash is a considerable operation
                    if (words_set.find(to_search) != words_set.end()) {
                        count++;
                        break;
                    }
                }
            }
        }
        // Total time complexity = O(M+N)
        
        return count;
    }
};