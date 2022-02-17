/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s = "";
        queue<TreeNode*> q;
        if(root==NULL)
            return s;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node==NULL)
                s.append("#,");
            else s.append(to_string(node->val)+',');
            if(node!=NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.size()==0 or data[0]=='#')
            return NULL;
        stringstream ss(data);
        string curr;
        getline(ss,curr,',');
        TreeNode* root = new TreeNode(stoi(curr));
        queue<TreeNode*> q;
        q.push(root);
        while(getline(ss,curr,','))
        {
            auto node = q.front();
            q.pop();
            if(curr=="#")
            {
                node->left = NULL;
            }
            else
            {
                node->left = new TreeNode(stoi(curr));
                q.push(node->left);
            }
            if(getline(ss,curr,','))
            {
                if(curr=="#")
                    {
                        node->right = NULL;
                    }   
                else
                    {
                        node->right = new TreeNode(stoi(curr));
                        q.push(node->right);
                    }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;