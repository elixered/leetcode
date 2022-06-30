class AutocompleteSystem {
public:
    
    class TrieNode{
        public:
        unordered_map<char, TrieNode*> children;
        string str;
        int count;
        TrieNode(){
            str = "";
            count = 0;
        }
    };
    
    void insert(string s, int times){
        TrieNode* curr = root;
        for(auto c:s){
            if(curr->children[c] == NULL)
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->str = s;
        curr->count += times;
    }
    
    void dfs(TrieNode* temp){
        if(temp == NULL) return;
        if(temp->str != "")
            q.push({temp->str,temp->count});
        for(auto& next:temp->children)
            dfs(next.second);
    }
    
    TrieNode* root = new TrieNode();

    struct comp{
        bool operator() (pair<string, int>& a, pair<string, int>& b){
            return a.second<b.second || a.second==b.second && a.first>b.first;
        }
    };
    
    priority_queue<pair<string, int>, vector<pair<string, int> >, comp> q;
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i=0; i<times.size(); ++i)
            insert(sentences[i],times[i]);
    }
    
    string s = "";
    TrieNode* curr = root;
    
    vector<string> input(char c) {
        q = priority_queue<pair<string, int>, vector<pair<string, int> >, comp>();
        if(c == '#'){
            insert(s,1);
            s.clear();
            curr = root;
            return {};
        }
        s += c;
        if(curr && curr->children.count(c))
            curr = curr->children[c];
        else{
            curr = NULL;
            return {};
        }
        if(curr->str != "")
            q.push({curr->str,curr->count});
        for(auto& e:curr->children)
            dfs(e.second);
        vector<string> res;
        while (!q.empty() && res.size()<3){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */