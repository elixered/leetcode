class Solution {
public:
    int dp[31][31][31];                                //-1 non processed, 1 matches, 0 not matches
    
    int fn(int start1, int start2, int len, string&s1, string& s2){
        int &res = dp[start1][start2][len];                       //Now res will refer to our current state
        
        //base case 0
        if(len==1){
            if(s1[start1]==s2[start2] ) return res = 1;
            else return res=0;
        }
		
        //base case 1
        if(res!=-1) return res;                       //already processed, reuse it
		
        res = 0;
        //without swap
        for(int i=1; i<len; i++){
            int decision = ( fn(start1, start2, i, s1, s2) & fn(start1+i, start2+i, len-i, s1, s2) );     //true only if x and y both matches
            res |= decision;
        }
		
        //with swap
        for(int i=1; i<len; i++){
            int decision = fn(start1, start2+len-i, i, s1, s2) & fn(start1+i, start2, len-i, s1, s2);     //true only if y and x matches
            res |= decision;
        }
        return res;
		
    }
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp) );
        return fn(0, 0, s1.size(), s1, s2);
    }
};