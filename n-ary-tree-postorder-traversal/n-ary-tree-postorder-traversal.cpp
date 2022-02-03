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

class Solution {
public:
    vector<int> ans;
    void preorderr(Node* root)
    {
        if(root==NULL) return;
        for(auto &it:root->children)
            preorderr(it);
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        preorderr(root);
        return ans;
    }
};