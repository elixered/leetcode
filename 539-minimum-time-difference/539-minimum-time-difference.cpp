class Solution {
public:
    int findMinDifference(vector<string>& t) {
        int ans = INT_MAX;
        auto cmp = [](string a, string b){
            int x = stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
            int y = stoi(b.substr(0,2))*60 + stoi(b.substr(3,2));
            return x<y;
        };
        sort(t.begin(),t.end(),cmp);
        int i = 0, j = t.size()-1;
        int last = stoi(t[j].substr(0,2))*60 + stoi(t[j].substr(3,2));
        while(i<j)
        {
            int a = stoi(t[i].substr(0,2))*60 + stoi(t[i].substr(3,2));
            int b = stoi(t[i+1].substr(0,2))*60 + stoi(t[i+1].substr(3,2));
            ans = min({1440-last+a,b-a,ans});
            i++;
        }
        return ans;
    }
};
