/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> set;
    TreeNode* root;
    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        set.insert(0);
        preorder(root);
    }
    void preorder(TreeNode* root)
    {
        if(root==NULL) return;
        set.insert(root->val);
        if(root->left)
        {
            root->left->val = 2*root->val+1;
            preorder(root->left);
        }
        if(root->right)
        {
            root->right->val = 2*root->val+2;
            preorder(root->right);
        }
    }
    
    bool find(int target) {
        return set.find(target)!=set.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */