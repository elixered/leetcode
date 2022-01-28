struct Node{
    Node* child[26];
    bool isEnd;
    Node()
    {
        isEnd = false;
        memset(child,NULL,sizeof(child));
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(auto c:word)
        {
            int idx = c-'a';
            if(temp->child[idx]==NULL)
                temp->child[idx] = new Node();
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        return find(word,0,root);
    }
private:
    bool find(string &word, int i, Node* parent)
    {
        if(i==word.size())
            return parent->isEnd;
        char c = word[i];
        int idx = c-'a';
        if(c!='.')
        {
            if(parent->child[idx]==NULL)
                return false;
            return find(word,i+1,parent->child[idx]);
        }
        bool flag = false;
        for(char ch='a'; ch<='z'; ch++)
        {
            if(parent->child[ch-'a'])
                flag = flag or find(word,i+1,parent->child[ch-'a']);
        }
        return flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */