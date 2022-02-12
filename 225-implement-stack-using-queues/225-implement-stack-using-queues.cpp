class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        for(int i=1; i<n ;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        int n = q1.size();
        for(int i=1; i<n ;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        q1.push(x);
        return x;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */