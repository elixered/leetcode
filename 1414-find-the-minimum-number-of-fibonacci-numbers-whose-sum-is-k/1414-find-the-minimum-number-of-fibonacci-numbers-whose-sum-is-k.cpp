class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        set<int> fibs;
        int prev = 1;
        int curr = 1;
        fibs.insert(1);
        while(prev<=k)
        {
            int next = prev+curr;
            prev = curr;
            curr = next;
            fibs.insert(next);
        }
        int count = 0;
        while(k>0)
        {
            auto itr = fibs.lower_bound(k);
            if(*itr==k)
                return count+1;
            {
                itr--;
                k -= *itr;
                count++;
            }
        }
        return count;
    }
};