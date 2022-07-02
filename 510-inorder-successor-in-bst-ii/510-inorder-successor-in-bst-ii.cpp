/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right){
            node = node->right;
            while(node->left)
                node = node->left;
            return node;
        }
        else{
            while(node->parent){
                auto prev = node;
                node = node->parent;
                if(node->left == prev)
                    return node;
            }
        }
        return NULL;
    }
};