class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i=0; i<32; ++i){
            int x = ((a&(1<<i)) != 0);
            int y = ((b&(1<<i)) != 0);
            int z = ((c&(1<<i)) != 0);
            if(z == 1 && x == 0 && y == 0)
                cnt++;
            else if(z == 0){
                if(x)
                    cnt++;
                if(y)
                    cnt++;
            }
        }
        return cnt;
    }
};