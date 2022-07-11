class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int a=A.size(),b=B.size();
        vector<int>lps(b);
       //Making LPS array using string 'B'
	   lps[0]=0;
        for(int j=0,i=1;i<b;)
        {
            if(B[i]==B[j])
                lps[i++]=++j;
            else if(j!=0)
                j=lps[j-1];
            else
                lps[i++]=0;
        }
        
        //Search pattern 'B' in string 'A' in a circular fashion
		//variable 'i' represents the starting index of pattern 'B' in string 'A' 
		//variable 'j' points to the current index in both strings 'A' and 'B'
		//(i+j)%a represents circular next index in 'A', as if it were linearly repeted
        for(int i=0,j=0;i<a;)
        {
            if(B[j]==A[(i+j)%a])
                ++j;//check for next in both
            if(j==b)//returns suitable answer
            {
                if((i+j)%a)
                    return (i+j)/a+1;
                return (i+j)/a;
            }
            else if(i<a and B[j]!=A[(i+j)%a])
            {
                if(j!=0)
                {
                    i+=(j-lps[j-1]);//updating 'i' here helps to keep pointed to the same position in 'A'
                    j=lps[j-1];
                }
                else
                    ++i;//even if no match found for the first letter of the pattern increment 'i'
            }
            
        }
        return -1;//if not possible to represent as multiple of 'A' return '-1'
    }
};