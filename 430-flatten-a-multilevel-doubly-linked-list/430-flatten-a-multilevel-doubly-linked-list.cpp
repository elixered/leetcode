/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        Node* c = head->child;
        head->child = NULL;
        Node* chi = flatten(c);
        Node* nex = flatten(head->next);
        if(!chi && !nex) return head;
        else
        if(chi==NULL)
        {
            head->next = nex;
            nex->prev = head;
        }
        else if(nex==NULL)
        {
            head->next = chi;
            chi->prev = head;
        }
        else
        {
            head->next = chi;
            chi->prev = head;
            Node* last = chi;
            while(last->next)
                last = last->next;
            last->next = nex;
            nex->prev = last;
        }
        return head;
    }
};