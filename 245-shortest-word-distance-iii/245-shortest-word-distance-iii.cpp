class Solution {
public:
    int shortestWordDistance(vector<string>& words, string w1, string w2) {
        int i = -1, j = -1;
        int prev = -1;
        int ans = INT_MAX;
        bool a = true, b = true;
        int n = words.size();
        while(i<n && j<n){
            if(a == true){
                ++i;
                while((i<n && words[i]!=w1) or i==j) ++i;
            }
            if(b == true){
                ++j;
                while((j<n && words[j]!=w2) or j==i) ++j;
            }
            if(i<n && j<n)
                ans = min(ans,(int)abs(i-j));
            if(i < j){
                a = true, b = false;
            }
            else{
                b = true, a = false;
            }
        }
        return ans;
    }
};