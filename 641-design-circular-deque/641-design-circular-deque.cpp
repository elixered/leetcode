class MyCircularDeque {
public:
    int k,sz;
    struct Node{
        int val;
        Node* next;
        Node* prev;
        Node(int v)
        {
            val = v;
            next = NULL;
            prev = NULL;
        }
    };
    Node *front,*back;
    MyCircularDeque(int k) {
        this->k = k;
        sz = 0;
        front = NULL, back = NULL;
    }
    
    bool insertFront(int value) {
        if(k==sz) return false;
        Node* newNode = new Node(value);
        sz++;
        if(front==NULL && back==NULL)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(k==sz) return false;
        Node* newNode = new Node(value);
        sz++;
        if(front==NULL && back==NULL)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        return true;
    }
    
    bool deleteFront() {
        if(sz==0) return false;
        sz--;
        Node* temp = front;
        if(front==back)
        {
            front = NULL;
            back = NULL;
        }
        else 
        {
            front = front->next;
            front->prev = NULL;
        }
        delete temp;
        return true;
    }
    
    bool deleteLast() {
        if(sz==0) return false;
        sz--;
        Node* temp = back;
        if(front==back)
        {
            front = NULL;
            back = NULL;
        }
        else 
        {
            back = back->prev;
            back->next = NULL;
        }
        delete temp;
        return true;
    }
    
    int getFront() {
        if(sz==0) return -1;
        return front->val;
    }
    
    int getRear() {
        if(back==NULL) return -1;
        return back->val;
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */