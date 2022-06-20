class Solution {
public:
    
    struct Node{
        bool isEnd;
        vector<Node*> children;
        Node(){
            isEnd = true;
            children = vector<Node*>(26,NULL);
        }
    };
    
    Node* root;
    
    bool insert(string& w){
        bool flag = false;
        Node* curr = root;
        for(auto c:w){
            if(curr->children[c-'a']==NULL){
                flag = true;
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
        return flag;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        root = new Node();
        for(auto& w:words){
            reverse(w.begin(),w.end());
        }
        auto cmp = [](string& a, string & b){
            return a.size() > b.size();
        };
        sort(words.begin(),words.end(),cmp);
        int ans = 0;
        for(auto w:words){
            if(insert(w) == true)
                ans += w.size()+1;
        }
        return ans;
    }
};