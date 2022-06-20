class Solution {
  public:
  // the smallest (first) and the largest (last) nodes
  Node* first = NULL;
  Node* last = NULL;

  void helper(Node* node) {
    if (node) {
      // left
      helper(node->left);
      // node 
      if (last) {
        // link the previous node (last)
        // with the current one (node)
        last->right = node;
        node->left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;
      // right
      helper(node->right);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    helper(root);
    // close DLL
    last->right = first;
    first->left = last;
    return first;
  }
};