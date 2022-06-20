/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node* prev = NULL;
        Node *first=NULL, *last=NULL;
        stack<Node*> st;
        while(root or !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            auto curr = st.top();
            st.pop();
            if(prev){
                prev->right = curr;
                curr->left = prev;
            }
            else first = curr;
            prev = curr;
            root = curr->right;
        }
        last = first;
        Node* head = first;
        while(last && last->right){
            if(last->val < head->val)
                head = last;
            last = last->right;
        }
        first->left = last;
        last->right = first;
        return head;
    }
};
// class Solution {
// public:
//     Node* treeToDoublyList(Node* root) {
//         if (!root) { return root; }
        
//         stack<Node*> nodes;
//         // we need to keep track of first and last nodes
//         Node* first = nullptr;
//         Node* last = nullptr;

//         // standard iterative in-order traversal using a stack
//         while (root || !empty(nodes)) {
//             while (root) {
//                 nodes.emplace(root);
//                 root = root->left;
//             }

//             root = nodes.top();
//             nodes.pop();
            
//             if (last) {
//                 last->right = root;
//                 root->left = last;
//             } else {
//                 first = root;  // only set once
//             }
//             last = root; // keep track of last node
//             root = root->right;
//         }
        
//         // connect first/last to make list circular
//         first->left = last;
//         last->right = first;
        
//         return first;
//     }
// };