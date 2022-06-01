class Solution {
public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (auto num : arr)
            counter[num]++;
        
        for (auto it : counter)
            pq.push(it.second);
        
        while (k) {
            if (pq.top() > k)
                break;
            
            k -= pq.top(); pq.pop();
        }
        
        return pq.size();                    
    }
};