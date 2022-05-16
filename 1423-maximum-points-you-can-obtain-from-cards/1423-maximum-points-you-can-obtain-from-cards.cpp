class Solution {
public:
    #define ll long long
    int maxScore(vector<int>& a, int k) {
        vector<int> front(k),end(k);
        int n = a.size();
        for(int i=0; i<k; i++)
        {
            if(i==0)
            {
                front[i] = a[i];
                end[i] = a[n-1-i];
            }
            else
            {
                front[i] = front[i-1]+a[i];
                end[i] = end[i-1]+a[n-i-1];
            }
        }
        int ans = 0;
        for(int i=0; i<k-1; i++)
        {
            ans = max(ans,front[i]+end[k-i-2]);
        }
        ans = max(ans,front[k-1]);
        ans = max(ans,end[k-1]);
        return ans;
    }
};