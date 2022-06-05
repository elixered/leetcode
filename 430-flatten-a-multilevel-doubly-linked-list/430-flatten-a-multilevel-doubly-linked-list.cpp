
class Solution {
public:
    Node* flatten(Node* head) {
        Node* h = head;
        for(h; h!=NULL; h = h->next)
        {
            if(h->child)
            {
                Node* temp = h->next;
                h->next = h->child;
                h->child = NULL;
                h->next->prev = h;
                Node* last = h->next;
                while(last->next)
                    last = last->next;
                last->next = temp;
                if(temp)
                temp->prev = last;
            }
        }
        return head;
    }
};