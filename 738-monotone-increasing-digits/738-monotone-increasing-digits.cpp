class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        
        queue<long>q;
        for (int i = 1; i <= 9; i++)
            q.push(i);
        
        int res =0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            
            if (t > N) break;
            res = max(res, t);
            
            int r = t % 10;
            for (int i = r; i <= 9; i++)
                q.push((long)t*10 + i);
        }
        
        return res;
    }
};