class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool isLTR = true;
        while(!dq.empty()) {
            int n = dq.size();
            vector<int> currLevel;
            if(isLTR) {
                isLTR = false;
                for(int i=0;i<n;++i) {
                    auto curr = dq.front();
                    dq.pop_front();
                    currLevel.push_back(curr->val);
                    if(curr->left)
                        dq.push_back(curr->left);
                    if(curr->right)
                        dq.push_back(curr->right);
                }
            } else {
                isLTR = true;
                for(int i=0;i<n;++i) {
                    auto curr = dq.back();
                    dq.pop_back();
                    currLevel.push_back(curr->val);
                    if(curr->right)
                        dq.push_front(curr->right);
                    if(curr->left)
                        dq.push_front(curr->left);
                }
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};