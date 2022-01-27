struct node{
    int isEnd;
    vector<node*> children;
    node()
    {
        isEnd = 0;
        children = vector<node*>(26,NULL);
    }
};

class Trie {
public:
    node *root;
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* curr = root;
        for(auto ch:word)
        {
            int idx = ch-'a';
            if(curr->children[idx]==NULL)
                curr->children[idx] = new node();
            curr = curr->children[idx];
        }
        curr->isEnd = 1;
    }
    
    bool search(string word) {
        node* curr = root;
        for(auto ch:word)
        {
            int idx = ch-'a';
            if(curr->children[idx]==NULL)
                return false;
            curr = curr->children[idx];
        }
        return curr->isEnd == 1;
    }
    
    bool startsWith(string word) {
         node* curr = root;
        for(auto ch:word)
        {
            int idx = ch-'a';
            if(curr->children[idx]==NULL)
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */