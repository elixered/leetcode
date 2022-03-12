/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        map<Node*,Node*> map;
        Node *temp =head;
        while(temp !=NULL)
        {
            Node *newNode = new Node(temp->val);
            map[temp] = newNode;
            temp = temp->next;
        }
        Node *newHead = map[head];
        newHead->next = map[head->next];
        newHead->random = map[head->random];
        Node *ans = newHead;
        head = head->next;
        while(head!=NULL)
        {
            
           ans = map[head];
           
        ans->next = map[head->next];
        ans->random = map[head->random];
            head = head->next;
        }
        return newHead;
    }
};