class MyHashSet {
public:
    struct node{
        int val;
        node *next;
        node(int data)
        {
            val = data;
        }
    };
    vector<node*> hm;
    int sz = 100007;
    MyHashSet() {
        hm = vector<node*>(sz,NULL);
    }
    
    void add(int key) {
        int hash = key%sz;
        node *newnode = new node(key);
        if(hm[hash]==NULL)
        {
            hm[hash] = newnode;
        }
        else
        {
            node *temp = hm[hash];
            node *prev = NULL;
            while(temp)
            {
                if(temp->val==key)
                    return;
                prev = temp;
                temp = temp->next;
            }
            prev->next = newnode;
        }
    }
    
    void remove(int key) {
        int hash = key%sz;
        if(contains(key)==false)
            return;
        node *prev = NULL;
        node *curr = hm[hash];
        if(curr && curr->val==key)
        {
            node* temp = curr;
            curr = curr->next;
            delete temp;
            hm[hash] = NULL;
            return;
        }
        else
        {
            while(curr && curr->val!=key)
            {
                prev = curr;
                curr  = curr->next;
            }
            node* temp = curr;
            prev->next = curr->next;
            delete temp;
            return;
        }
    }
    
    bool contains(int key) {
        int hash = key%sz;
        node* curr = hm[hash];
        while(curr)
        {
            if(curr->val==key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */