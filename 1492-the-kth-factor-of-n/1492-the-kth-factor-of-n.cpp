class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> right;
        for(int i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                if(--k==0)
                    return i;
                else if(i*i!=n)
                    right.push_back(n/i);
            }
        }
        if(right.size()<k) return -1;
        else return right[right.size()-k];
    }
};