class Solution {
public:
    string tree2str(TreeNode* root) {
		string ans = to_string(root->val);
		if (root->left) //left side check
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) { //right side check
			if (!root->left) ans += "()"; //left side not present, but right side present
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
	}
};
