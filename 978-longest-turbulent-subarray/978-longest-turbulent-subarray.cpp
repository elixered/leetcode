class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int increase = 1; int decrease = 1; int max_len = 1;
        for(int i=0; i < A.size()-1; i++){
            if(A[i] > A[i+1]){
                increase = decrease + 1;
                decrease = 1;
            }
            else if(A[i] < A[i+1]){
                decrease = increase + 1;
                increase = 1;
            }
            else{
                increase = 1;
                decrease = 1;
            }
            max_len = max(max_len, max(increase, decrease));
        }
        return max_len;
    }
};