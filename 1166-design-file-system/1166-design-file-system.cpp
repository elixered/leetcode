class FileSystem {
public:
    
    class Node{
        public:
        int value;
        unordered_map<string,Node*>  children;
        Node(int value){
            this->value = value;
        }
    };
    
    
    FileSystem() {
        root = new Node(-1);
    }
    
    bool createPath(string path, int value) {
        vector<string> paths = split(path);
        Node* curr = root;
        int i = 0;
        int n = paths.size();
        for(i=0; i<n; i++){
            string p = paths[i];
            if(!curr->children[p]) {
                break;
            }
            curr = curr->children[p];
        }
        if(i==n-1){
            curr->children[paths[i]] = new Node(value);
            return true;
        }
        return false;
    }
    
    int get(string path) {
        vector<string> paths = split(path);
        Node* curr = root;
        for(auto p:paths){
            if(!curr->children[p]) return -1;
            curr = curr->children[p];
        }
        return curr->value;
    }
private:
    Node* root;
    vector<string> split(string s){
        s = s.substr(1);
        stringstream ss(s);
        string word;
        vector<string> ans;
        while(getline(ss,word,'/')){
            ans.push_back(word);
        }
        return ans;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */