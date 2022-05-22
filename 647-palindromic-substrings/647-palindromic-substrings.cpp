class Solution {
public:
    int countSubstrings(string s) {
        int count=0,mid,left,right=0;
        int length=s.size();
        for(int i=0;i<length;i++)
        {
            mid=i;
            left=mid-1;
            right=mid+1;
            count++;                        // Single character itself is a plaindrome
            
            while(left>=0 && right<length)  // For Odd Palindrome like 'aabaa' if we are at 'b' 
            {
                if(s[left]==s[right])
                {
                    count++;
                    left--;
                    right++;
                }
                else
                    break;
            }
            
            if(i<s.size()-1 && s[i]==s[i+1])  // For Even Palindrome like 'abccba' if we are at 1st 'c' then s[i]==s[i+1]
            {
                count++;                     //For what we have already checked i.e s[i]==s[i+1]
                left=mid-1;
                right=mid+2;
                
                while(left>=0 && right<length)
                {
                    if(s[left]==s[right])
                    {
                        count++;
                        left--;
                        right++;
                    }
                    else
                        break;
                }
            }
            
        }
        return count;
    }
};