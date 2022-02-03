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
    int res = 1;
    int solve(Node* root)
    {
        if(root==NULL) return 0;
        if(root->children.size()==0) return 1;
        int ans = 0;
        for(auto it: root->children)
            ans = max(ans,solve(it)+1);
        res = max(ans,res);
        return ans;
    }
    int maxDepth(Node* root) {
        if(!root) return 0;
        solve(root);
        return res;
    }
};