class MyCircularDeque {
public:
    int front, rear, k, size;
    vector<int> nums;

    MyCircularDeque(int k) {
        front = -1;
        this->k = k;
        size = 0;
        rear = -1;
        nums = vector<int>(k,0);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        size++;
        front = (front-1+k)%k;
        if(size==1)
            rear = front;
        nums[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        size++;
        rear = (rear+1)%k;
        if(size==1)
            front = rear;
        nums[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front = (front+1)%k;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = (rear-1+k)%k;
        size--;
        return true;
    }
    
    int getFront() {
         return isEmpty() ? -1 : nums[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : nums[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
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