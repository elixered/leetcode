class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for(int i=0; i+m <= arr.size(); ++i){
            string s;
            for(int j=0; j<m; ++j)
                s += to_string(arr[i+j]);
            int cnt = 1;
            for(int j=i+m; j+m <= arr.size(); j+=m){
                string t;
                for(int k=0; k<m; ++k)
                    t += to_string(arr[j+k]);
                if(t==s)
                    cnt++;
                else break;
            }
            if(cnt >= k) return true;
        }
        return false;
    }
};