struct Node{
    Node* child[26];
    bool isEnd;
    Node(){
        isEnd = false;
        memset(child,NULL,sizeof(child));
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string& word)
    {
        Node* temp = root;
        for(auto& c:word)
        {
            int idx = c-'a';
            if(temp->child[idx]==NULL)
                temp->child[idx] = new Node();
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }
    bool check(string& word)
    {
        Node* temp = root;
        for(auto& c:word)
        {
            int idx = c-'a';
            if(temp->child[idx]->isEnd==false)
                return false;
            temp = temp->child[idx];
        }
        return true;
    }
};
class Solution {
public:
     
    string longestWord(vector<string>& words) {
        string ans = "";
        Trie* trie = new Trie();
        for(auto& s:words)
            trie->insert(s);
        for(auto& s:words)
        {
            if(trie->check(s))
            {
                if(s.size()>ans.size())
                    ans = s;
                else if(s.size()==ans.size())
                    ans = min(ans,s);
            }
        }
        return ans;
    }
};