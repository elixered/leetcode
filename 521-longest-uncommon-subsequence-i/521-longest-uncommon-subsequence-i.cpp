class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a!=b)
            return max((int)a.size(),(int)b.size());
        else return -1;
    }
};