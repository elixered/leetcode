class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        bool flag = true;
        for(auto it:arr)
            map[(it%k+k)%k]++;
        int count = 0;
        for(auto it:arr)
        {
            int x = (it%k+k)%k;
            if(map[x]==0) continue;
            map[x]--;
            int y = k-x;
            if(y==k) y=0;
            if(map.find(y)==map.end()) return false;
            else if(map[y]==0) return false;
            else map[y]--;
            count += 2;
        }
        return count == arr.size();
    }
};