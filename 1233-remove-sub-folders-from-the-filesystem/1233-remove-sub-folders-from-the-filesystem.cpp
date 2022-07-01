class Solution {
public:
    
    class node{
    public:
        unordered_map<string,node*> children;
        string str;
        bool isEnd;
        node(string s){
            str = s;
            isEnd = false;
        }
    };
    
    node *root = new node("");
    
    void insert(vector<string> path){
        node *curr = root;
        for(auto s:path){
            if(curr->children.count(s) == 0)
                curr->children[s] = new node(s);
            curr = curr->children[s];
            if(curr->isEnd == true) return;
        }
        curr->isEnd = true;
    }
    
    void dfs(node* curr, vector<string>& ans, string s){
        if(!curr) return;
        s += curr->str;
        if(curr->isEnd){
            ans.push_back(s);
            return;
        }
        for(auto it:curr->children){
            s += "/";
            dfs(it.second,ans,s);
            s.pop_back();
        }
        return;
    }
    
    vector<string> parse(string& s){
        stringstream ss(s);
        string word;
        getline(ss,word,'/');
        vector<string> ans;
        while(getline(ss,word,'/'))
            ans.push_back(word);
        return ans;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        for(auto& f:folder){
            auto parsed = parse(f);
            insert(parsed);
        }
        auto curr = root;
        vector<string> ans;
        dfs(curr,ans,"");
        return ans;
    }
};