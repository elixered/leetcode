struct Node{
    Node* next;
    int val;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* dummy,*tail;
    int size;
    MyLinkedList() {
        dummy = new Node(-1);
        tail = dummy;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        Node* curr = dummy;
        for(int i=0; i<=index; i++)
            curr = curr->next;
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* nex = dummy->next;
        Node* curr = new Node(val);
        dummy->next = curr;
        curr->next = nex;
        // if(tail==dummy)
        //     tail = dummy->next;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp=dummy;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(val);
        // tail->next = new Node(val);
        // tail = tail->next;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        size++;
        Node* prev = dummy;
        for(int i=0; i<index; i++)
        {
            if(prev==NULL) return;
            else prev = prev->next;
        }
        Node* nex = prev->next;
        prev->next = new Node(val);
        prev->next->next = nex;
        // if(tail==prev)
        //     tail = prev->next;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) return;
        size--;
        Node* prev = dummy;
        for(int i=0; i<index; i++)
        {
            prev = prev->next;
        }
        if(!prev->next) return;
        Node* curr = prev->next;
        Node* currnext = curr->next;
        prev->next = currnext;
        // if(index==size-1) tail = prev;
        delete curr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */