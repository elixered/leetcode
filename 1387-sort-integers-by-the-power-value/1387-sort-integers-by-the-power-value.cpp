class Solution {
public:
    unordered_map<int,int> mp;
    
    int solve(int i){
        if(i==1) return 0;
        if(mp.count(i)) return mp[i];
        int res = 0;
        if(i%2==0)
            res = solve(i/2)+1;
        else res = solve(3*i+1)+1;
        return mp[i] = res;
    }
    
    int getKth(int lo, int hi, int k) {
        for(int i=lo; i<=hi; ++i)
            solve(i);
        priority_queue<pair<int,int>> pq;
        for(int i=lo; i<=hi; ++i){
            pq.push({mp[i],i});
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top().second;
    }
};