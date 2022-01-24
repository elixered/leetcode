class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i=1; i<word.size(); i++)
        {
            if((islower(word[0]) && isupper(word[i]))
               or (isupper(word[1])!= isupper(word[i]))
              )
               return false;
        }
        return true;
    }
};