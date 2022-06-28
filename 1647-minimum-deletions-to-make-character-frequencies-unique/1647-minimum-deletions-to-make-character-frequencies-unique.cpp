class Solution {
public:
    int minDeletions(string s) {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }
        
        // Add the frequencies to priority queue
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                pq.push(frequency[i]);
            }
        }
        
        int deleteCount = 0;
        while (pq.size() > 1) {
            int topElement  = pq.top();
            pq.pop();
            
            // If the top two elements in the priority queue are the same
            if (topElement == pq.top()) {
                // Decrement the popped value and push it back into the queue
                if (topElement - 1 > 0) {
                    pq.push(topElement - 1);
                }
                deleteCount++;
            }
        }
        
        return deleteCount;
    }
};