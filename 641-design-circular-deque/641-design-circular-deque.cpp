class MyCircularDeque {
public:
    vector<int> deq;
    int k;
    MyCircularDeque(int k) {
        this->k = k;
        deq = vector<int>();
    }
    
    bool insertFront(int value) {
        if(deq.size()==k) return false;
        vector<int> temp ;
        temp.push_back(value);
        for(auto it:deq)
            temp.push_back(it);
        deq = temp;
        return true;
    }
    
    bool insertLast(int value) {
        if(deq.size()==k) return false;
        deq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(deq.size()==0) return false;
        vector<int> temp;
        for(int i=1; i<deq.size(); i++)
            temp.push_back(deq[i]);
        deq = temp;
        return true;
    }
    
    bool deleteLast() {
        if(deq.size()==0) return false;
        deq.pop_back();
        return true;
    }
    
    int getFront() {
        if(deq.size()==0) return -1;
        return deq[0];
    }
    
    int getRear() {
        if(deq.size()==0) return -1;
        return deq.back();
    }
    
    bool isEmpty() {
        return deq.size()==0;
    }
    
    bool isFull() {
        return deq.size()==k;
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