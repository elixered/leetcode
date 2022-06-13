class trie {
    trie* ch[27];
    int weight;
public:
    trie() {
        memset(ch, 0, sizeof(ch));
        weight = 0;
    }
    void insert(string str, int weight) {
        trie* node = this;
        for (char c: str) {
            if (node->ch[c - 'a'] == NULL)
                node->ch[c - 'a'] = new trie();
            node = node->ch[c - 'a'];
            node->weight = weight;
        }
    }
    int startsWith(string str) {
        trie* node = this;
        for (char c: str) {
            if (node->ch[c - 'a'] == NULL)
                return -1;
            node = node->ch[c - 'a'];
        }
        return node->weight;
    }
};
class WordFilter {
public:
    trie root;
    WordFilter(vector<string>& words) {
        int idx = 0;
        for (string word: words) {
            root.insert(word, idx);
            string tmp = "{" + word;
            for (int i = word.length() - 1; i >= 0; i--) {
                string newword = word[i] + tmp;
                tmp = newword;
                root.insert(newword, idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + "{" + prefix;
        return root.startsWith(word);
    }
};