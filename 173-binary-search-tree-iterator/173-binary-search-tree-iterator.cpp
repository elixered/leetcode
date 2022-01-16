
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto x = st.top();
        st.pop();
        pushAll(x->right);
        return x->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */