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
    unordered_map<TreeNode*,TreeNode*> parent;
    unordered_map<TreeNode*,int> outdegree;
    
    void inorder(TreeNode* root){
        if(root==NULL) return;
        outdegree[root] = 0;
        if(root->left){
            parent[root->left] = root;
            outdegree[root]++;
            inorder(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            outdegree[root]++;
            inorder(root->right);
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        inorder(root);
        queue<TreeNode*> q;
        for(auto it:outdegree){
            if(it.second==0)
                q.push(it.first);
        }
        while(q.size()){
            vector<int> temp;
            int m = q.size();
            while(m--){
                auto x = q.front();
                q.pop();
                temp.push_back(x->val);
                outdegree[parent[x]]--;
                if(outdegree[parent[x]]==0)
                    q.push(parent[x]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};