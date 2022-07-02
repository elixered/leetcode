class Solution {
public:
    
    int move(string& source, string& target, int i){
        int j = 0;
        int n = source.size();
        int m = target.size();
        while(i<m && j<n){
            if(source[j]==target[i]){
                i++;
            }
            j++;
        }
        return i;
    }
    
    int shortestWay(string source, string target) {
        int i = 0;
        int n = target.size();
        int s = 0;
        while(i<n){
            int j = move(source,target,i);
            if(i==j) return -1;
            i = j;
            s++;
        }
        return s;
    }
};