/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        if(!root) return "#,";
        queue<Node*> q;
        q.push(root);
        s += to_string(root->val) + ",#,";
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto ch:node->children){
                s += to_string(ch->val) + ",";
                q.push(ch);
            }
            s += "#,";
        }
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        string s;
        getline(ss,s,',');
        if(s=="#") return NULL;
        Node* root = new Node(stoi(s));
        getline(ss,s,',');
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            while(getline(ss,s,',')){
                if(s=="#") break;
                auto newNode = new Node(stoi(s));
                node->children.push_back(newNode);
                q.push(newNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));