class Solution {
public:
    long long ans = 0, totalSum = 0;
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root); // First, get total sum of all nodes in the Binary Tree
        dfs(root); // Then dfs in post order to calculate sum of each subtree and its complement
        return ans % int(1e9+7);
    }
    
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int currSum = dfs(root->left) + dfs(root->right) + root->val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
};