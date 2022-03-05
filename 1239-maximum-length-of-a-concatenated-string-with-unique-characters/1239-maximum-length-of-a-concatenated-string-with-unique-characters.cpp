class Solution {
public:
    int ans = 0;
    
    void solve(unordered_set<char> set, string curr, vector<string>& arr, int idx)
    {
        ans = max(ans,(int)curr.size());
        if(idx>=arr.size()) return;
        solve(set,curr,arr,idx+1);
        bool f = true;
        string s = arr[idx];
        for(auto c:s)
        {
            if(set.find(c)!=set.end())
            {
                f = false;
                break;
            }
            else set.insert(c);
        }
        if(f==false) return;
        solve(set,curr+s,arr,idx+1);
    }
    
    int maxLength(vector<string>& arr) {
        unordered_set<char> set;
        solve(set,"",arr,0);
        return ans;
    }
};