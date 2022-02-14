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
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> q;
    CBTInserter(TreeNode* root) {
        this->root = root;
        bfs();
    }
    void bfs()
    {
        if(root==NULL) return;
        TreeNode* curr = root;
        queue<TreeNode*> que;
        que.push(curr);
        while(!que.empty())
        {
            auto node = que.front();
            que.pop();
            if(node->left)
                que.push(node->left);
            if(node->right)
                que.push(node->right);
            if(!node->left or !node->right)
                q.push(node);    
        }
    }
    int insert(int val) {
        if(root==NULL)
        {
            root = new TreeNode(val);
            return -1;
        }
        auto node = q.front();
        TreeNode* curr = new TreeNode(val);
        if(node->left==NULL)
        {
            node->left = curr;
            q.push(curr);
            return node->val;
        }
        else if(node->right==NULL)
        {
            node->right = curr;
            q.pop();
            q.push(curr);
            return node->val;
        }
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */