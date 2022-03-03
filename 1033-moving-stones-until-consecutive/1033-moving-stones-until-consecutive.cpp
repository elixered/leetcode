class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a>b) return numMovesStones(b,a,c);
        if(b>c) return numMovesStones(a,c,b);
        if(abs(a-b)<=1 && abs(b-c)<=1)
            return {0,0};
        int max = c-a-2;
        int min;
        if(b-a>2 && c-b>2)
            min = 2;
        else min = 1;
        return {min,max};
    }
};