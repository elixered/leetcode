class Solution {
    
private:
    struct TrieNode{
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode()
        {
            isEnd = false;
            children.resize(26,NULL);
        }
    };
    
     void insert(string word) {
        TrieNode* curr = node;
        for(auto ch:word)
        {
            if(curr->children[ch-'a']==NULL)
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    string getPrefix(string word)
    {
        string ans;
        TrieNode* curr = node;
        for(auto ch:word)
        {
            if(curr->children[ch-'a']!=NULL)
                ans.push_back(ch);
            else break;
            curr = curr->children[ch-'a'];
            if(curr->isEnd==true) return ans;
        }
        if(curr==NULL or curr->isEnd==false) return word;
        else return ans;
    }
    
    TrieNode* node;
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        node = new TrieNode();
        for(auto word:dictionary)
            insert(word);
        string ans;
        stringstream ss(sentence);
        string word;
        while(getline(ss,word,' '))
        {
            if(node->children[word[0]-'a']==NULL)
                ans += word + " ";
            else
                ans += getPrefix(word) + " ";
        }
        ans.pop_back();
        return ans;
    }
};