class CustomStack {
public:
    vector<int> stack;
    int cap,size;
    CustomStack(int maxSize) {
        cap = maxSize;
        size = 0;
    }
    
    void push(int x) {
        if(size < cap){
            stack.push_back(x);
            size++;
        }
    }
    
    int pop() {
        int x = -1;
        if(size>0){
            size--;
            x = stack.back();
            stack.pop_back();
        }
        return x;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(k,size); i++)
            stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */