class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = pow(10,9) + 7;
        stack<pair<int,int>> st_p, st_n;
        int n = arr.size();
        //left for distance of previous less element
        //right for distance of next less element
        vector<int> left(n), right(n);
        for(int i=0; i<n; i++)
        {
            left[i] = i+1;
            right[i] = n - i;
        }
        
        for(int i=0; i<n; i++)
        {
            //finding previous less
            while(!st_p.empty() && st_p.top().first > arr[i])
                st_p.pop();
            left[i] = st_p.empty() ? i+1 : i-st_p.top().second;
            st_p.push({arr[i],i});
            
            //finding next less element
            while(!st_n.empty() && st_n.top().first > arr[i])
            {
                auto x = st_n.top(); st_n.pop();
                right[x.second] = i - x.second;
            }
            st_n.push({arr[i],i});
        }
        
        int ans  = 0;
        for(int i=0; i<n; i++)
        {
            long long curr = (long long)left[i]*right[i]*arr[i];
            ans = (ans+curr)%mod;
        }
        return ans;
    }
};