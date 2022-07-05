class Solution {
public:
    vector<int> helper(TreeNode* root, int& res) {
        if (!root) return {0, 0, -2};
        
        auto l = helper(root->left, res);
        auto r = helper(root->right, res);

        int incrLen = 0, decrLen = 0;
        incrLen = max(incrLen, l[0] && l[2] + 1 == root->val ? l[0] + 1 : 1);
        incrLen = max(incrLen, r[0] && r[2] + 1 == root->val ? r[0] + 1 : 1);
        
        decrLen = max(decrLen, l[1] && l[2] - 1 == root->val ? l[1] + 1 : 1);
        decrLen = max(decrLen, r[1] && r[2] - 1 == root->val ? r[1] + 1 : 1);

        res = max(res, max(incrLen, decrLen));

        if (l[2] + 1 == root->val && root->val + 1 == r[2]) {
            res = max(res, l[0] + r[1] + 1);
        }
        
        if (l[2] - 1 == root->val && root->val - 1 == r[2]) {
            res = max(res, l[1] + r[0] + 1);
        }
        
        return {incrLen, decrLen, root->val};
    }
    
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};