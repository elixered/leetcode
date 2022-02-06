class MyCalendarTwo {
public:
    map<int,int> map;
    MyCalendarTwo() {
        
    }
    
    
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int sum = 0;
        for(auto it:map)
        {
            sum += it.second;
            if(sum>2)
            {
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */