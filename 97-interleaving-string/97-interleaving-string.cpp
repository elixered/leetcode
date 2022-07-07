class Solution {
public:
 bool isInterleave(string s1, string s2, string s3) {
    
    if(s3.length() != s1.length() + s2.length())
        return false;
    
    vector<bool> table(s2.size()+1,false);
    
    for(int i=0; i<s1.length()+1; i++){
        vector<bool> temp(s2.size()+1,false);
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                temp[j] = true;
            else if(i == 0)
                temp[j] = ( temp[j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                temp[j] = ( table[j] && s1[i-1] == s3[i+j-1]);
            else
                temp[j] = (table[j] && s1[i-1] == s3[i+j-1] ) || (temp[j-1] && s2[j-1] == s3[i+j-1] );
        }
        table = temp;
    }
    return table[s2.length()];
}
};