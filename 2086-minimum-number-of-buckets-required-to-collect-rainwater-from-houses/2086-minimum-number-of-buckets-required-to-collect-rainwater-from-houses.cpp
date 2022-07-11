class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; ++i){
            if(s[i] == 'H'){
                if(i-1 >= 0 && s[i-1] == 'B')
                    continue;
                else if(i+1 < n && s[i+1] == '.'){
                    s[i+1] = 'B';
                    count++;
                }
                else if(i-1 >=0 && s[i-1] == '.'){
                    s[i-1] = 'B';
                    count++;
                }
                else return -1;
            }
        }
        return count;
    }
};