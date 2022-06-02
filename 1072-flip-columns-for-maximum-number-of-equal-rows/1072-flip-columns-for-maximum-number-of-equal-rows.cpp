class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> hmap;
        for(auto x: matrix){
            string s=""; 
            //s keeps track of relative ordering of elements in a row w.r.t the first element
            int top=x[0];
            for(int i=0;i<x.size();i++){
                if(x[i]==top)
                    s+='1';
                else
                    s+='0';
            }
            hmap[s]++; 
        }
        
        int result=0;
        for(auto &[key,val]:hmap)
            result=max(result,val); 
        //rows that have identical relative ordering, can be simultaneously toggled columnwise in order to make all
        //elements of any of those rows unique. So the answer is maximum number of rows with identical relative ordering.
        return result;
    }
};