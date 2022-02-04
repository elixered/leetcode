class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        int count = 0;
        unordered_map<int,int> map;
        int maxlen = 0;
        map[0] = -1;
        for(int i=0; i<n; i++)
        {
            int curr = s[i]-'0';
            count = (count^(1<<curr));
            if(map.find(count)==map.end())
                map[count] = i;
                maxlen = max(maxlen,i-map[count]);
                int temp = count;
                for(int j=0; j<=9; j++)
                {
                    int curr = (temp^(1<<j));
                    if(map.find(curr)!=map.end())
                        maxlen = max(maxlen,i-map[curr]);
                }
        }
        return maxlen;
    }
};