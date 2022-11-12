class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() || small.top()>num)
        {
            small.push(num);
            if(small.size() > large.size()+1)
            {
                large.push(small.top());
                small.pop();
            }
        }
        else
        {
            large.push(num);
            if(large.size()>small.size()+1)
            {
                small.push(large.top());
                large.pop();
            }
        }
    }
    
    double findMedian() {
        double x = 0;
            if(small.size() == large.size())
                x += (small.top()+large.top())/2.0;
            else if(small.size()>large.size())
                x = small.top();
        else 
            x = large.top();
        return x;
    }
};

// *
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
