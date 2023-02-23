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
    TreeNode* recoverFromPreorder(string s) {
        int i = 0;
        int v = 0;
        int n = s.size();
        while(i<n && s[i]!='-'){
            v = v*10 + s[i]-'0';
            i++;
        }
        TreeNode* root = new TreeNode(v);
        stack<pair<int,TreeNode*>> st;
        st.push({0,root});
        while(i < n){
            int cnt = 0;
            while(i < n && s[i] == '-'){
                i++;
                cnt++;
            }
            int val = 0;
            while(i < n && s[i] != '-'){
                val = val*10 + s[i] - '0';
                i++;
            }
            while(st.top().first != cnt - 1)
                st.pop();
            auto& [depth,node] = st.top();
            TreeNode* curr = new TreeNode(val);
            if(cnt == depth+1){
                if(!node->left)
                    node->left = curr;
                else
                    node->right = curr;
            }
            st.push({cnt,curr});
        }
        return root;
    }
};