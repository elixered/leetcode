class node{
        public:
        int idx=-1;
        node * m['z'-'a'+1]= {NULL,};
    };
class Solution {
    vector<vector<int>> ans;
    int n=-1;
    node * root =new node();
    
    void insert(string &word, node *root, int idx){
        for(int i=0;i<word.length();i++){
            if(root->m[word[i]-'a'] == NULL) root->m[word[i]-'a'] = new node();
            root = root->m[word[i]-'a'];
        }
        root->idx = idx;
        return;
    }
    
     bool ispal(const string &word){
        int end=word.length();
        --end;
        int s=0;
        while(s<end){
            if(word[s]!=word[end]) return false;
            s++; end--;
        }
        return true;
    }
    
    void getbig(node * cur, string & t, int idx){
        for(int i=0;i<26;i++){//try every possible char
            if(cur->m[i] == NULL) continue;
            
            t.push_back('a'+i);
            if(cur->m[i]->idx!=-1 && ispal(t)) ans.push_back({idx,cur->m[i]->idx});
            getbig(cur->m[i], t, idx);
            t.pop_back();
        }
        return;
    }
    
    void getall(string &word, int idx, node * cur){
        for(int i=0;i<word.length();i++){
            if(cur->m[word[i]-'a'] == NULL) return;
            //present in trie
            cur = cur->m[word[i]-'a'];
            if(cur->idx != -1 && cur->idx!=idx && ((i+1)==word.length() || ispal(word.substr(i+1))))
                ans.push_back({idx,cur->idx});
        }
        string t;
        getbig(cur, t, idx);
        return;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        n=words.size();
        vector<int> p;
        int blankIdx=-1;
        for(int i=0;i<n;i++){
            if(words[i] == ""){
                blankIdx=i;
                continue;
            }
            string word=words[i];
            reverse(begin(word), end(word));
            insert(word, root, i);
            if(word == words[i]) p.push_back(i);
        }
        
        //1. consider all {"", "aba"} empty str ans
        if(blankIdx!=-1){
            for(auto i: p){
                ans.push_back({i,blankIdx});
                ans.push_back({blankIdx,i});
            }
        }
        
        for(int i=0;i<n;i++){
            if(words[i]=="") continue;
            getall(words[i], i, root);//gives all valid cases only
        }
        
        return ans;
    }
};