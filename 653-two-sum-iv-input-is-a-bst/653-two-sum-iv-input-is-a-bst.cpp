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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st1, st2;
        auto t1 = root, t2 = root;
        while(1)
        {
            while(t1)
            {
                st1.push(t1);
                t1 = t1->left;
            }
            while(t2)
            {
                st2.push(t2);
                t2 = t2->right;
            }
            if(st1.empty() or st2.empty())
                return false;
            t1 = st1.top();
            t2 = st2.top();
            int curr = t1->val + t2->val;
            if(curr==k)
            {
                if(t1!=t2)
                    return true;
                else return false;
            }
            else if(curr>k)
            {
               t2 = st2.top()->left;
               st2.pop();
                t1 = NULL;
            }
            else
            {
                t1 = st1.top()->right;
                t2 =NULL;
                st1.pop();
            }
        }
        return false;
    }
};