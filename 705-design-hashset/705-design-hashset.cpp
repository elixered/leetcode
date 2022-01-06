class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        next = nullptr;
    }    
};

class MyHashSet {
    Node* head;
public:
    MyHashSet() {
        head = nullptr;
    }
    
    void add(int key) {
        Node* new_node = new Node(key);
        new_node->next = head;
        head = new_node;
    }
    
    void remove(int key) {
        bool isKeyPresent = contains(key);
        if(isKeyPresent == false)
            return;
        
        // Delete the key.
        Node* dummy = new Node(1);
        dummy->next = head;
        
        Node* temp = head, *prev = dummy;
        // Remove all the occurences of key
        while(temp != nullptr) {
            if(temp->data == key) {
                prev->next = temp->next;
                Node* curr = temp;
                temp = temp->next;
                delete curr;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        head = dummy->next;
    }
    
    bool contains(int key) {
        Node* temp = head;
        while(temp != nullptr) {
            if(temp->data == key)
                return true;
            temp = temp->next;
        }
        
        return false;
    }
};