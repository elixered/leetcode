class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> maxHeap;
        for(auto it:stones)
            maxHeap.push(it);
        while(maxHeap.size()>1)
        {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if(a!=b)
                maxHeap.push(abs(a-b));
        }
        if(maxHeap.empty()) return 0;
        else return maxHeap.top();
    }
};