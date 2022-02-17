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
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        int idx = 1;
        st.push(root);
        for(; idx<preorder.size(); idx++)
        {
            int curr = preorder[idx];
            auto node = st.top();
            if(node->val > curr)
            {
                TreeNode* newNode = new TreeNode(curr);
                node->left = newNode;
                st.push(newNode);
            }
            else
            {
                while(!st.empty() && st.top()->val<curr)
                {
                    node = st.top();
                    st.pop();
                }
                TreeNode* newNode = new TreeNode(curr);
                node->right = newNode;
                st.push(newNode);
            }
        }
        return root;
    }
};