class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int sz = 0;
        for(auto c:s)
        {
            if(c=='(')
                size++;
            else if(size>0)
                size--;
            else sz++;
        }
        return sz+size;
    }
};