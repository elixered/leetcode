class Solution {
    unordered_set<int> set;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        bool flag = false;
        flag = flag or findTarget(root->left,k);
        if(flag) return true;
        if(set.find(k-root->val)!=set.end())
            return true;
        else
            set.insert(root->val);
        flag = flag or findTarget(root->right,k); 
        return flag;
    }
};